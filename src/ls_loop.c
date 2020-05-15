/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ls_loop.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/28 15:09:12 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/30 16:58:15 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ls_loop_break(char *opts, char *path)
{
	char			*s;

	if (!(s = ft_strchr(opts, '^')))
		ft_putchar('\n');
	else
		*s = '\0';
	ls_prtparent(path);
}

static void			ls_loop_content(char *opts, t_fdir *tmp, char dots)
{
	t_arraylist		*tmp_al;

	tmp_al = ls_populate_fdirs(opts, tmp);
	if (tmp->sl)
		free(tmp->sl);
	get_file_link(tmp);
	if ((!(S_ISDIR(tmp->stats->st_mode)) && tmp->sl == NULL) ||
		(!dots && isdots(tmp->name)) || (tmp->sl == NULL && \
		ft_strchr(opts, 'l') && !ft_strchr(opts, 'R') && !ls_isdir(tmp->name)))
	{
		del_fdir_arlst(tmp_al);
		return ;
	}
	if ((grab_entry(opts, tmp->name) || isdots(tmp->name)))
	{
		ls_loop_break(opts, tmp->path);
		ls_buckle(opts, tmp_al);
		del_fdir_arlst(tmp_al);
	}
	else if (ft_strchr(opts, 'R'))
	{
		if (tmp->name[0] != '.')
			ls_loop(opts, tmp_al, 0);
		del_fdir_arlst(tmp_al);
	}
}

void				ls_loop(char *opts, t_arraylist *fdirs, char dots)
{
	t_arraylist		*fn;
	t_arlst_iter	*iter;
	t_fdir			*tmp_dir;
	int				iter_ret;

	tmp_dir = NULL;
	if (!fdirs || !(fn = ls_dirs(opts, fdirs)))
		return ;
	iter = arlst_iter(fn);
	if (ft_strchr(opts, 'r'))
		iter->pip = iter->pop;
	iter_ret = 1;
	while (iter_ret && (tmp_dir = iter->pip(iter, &iter_ret)))
	{
		if (ft_strchr(opts, 'l') && ft_strchr(opts, 'R') && tmp_dir->sl != NULL)
			continue ;
		if (tmp_dir->sl == NULL || (tmp_dir->sl != NULL && !opts[0]) ||
			(tmp_dir->sl != NULL && !(ft_strchr(opts, 'l'))) ||
			(tmp_dir->sl != NULL && ft_strchr(opts, 'R') &&
				(!(S_ISLNK(tmp_dir->stats->st_mode))) && !opts_has_l(opts)))
			ls_loop_content(opts, tmp_dir, dots);
	}
	free(iter);
	if (fn)
		fn->del(fn);
}

void				ls_buckle(char *opts, t_arraylist *fdirs)
{
	if (!fdirs)
		return ;
	ls_print(opts, fdirs, true);
	if (ft_strchr(opts, 'R'))
		ls_loop(opts, fdirs, 0);
}
