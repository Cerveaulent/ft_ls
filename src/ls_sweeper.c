/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ls_sweeper.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/28 17:37:48 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/30 15:31:36 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static t_arraylist	*ls_files(t_arraylist *fdir)
{
	t_arraylist		*fn;
	t_arlst_iter	*iter;
	int				iter_ret;
	t_fdir			*tmp_fdir;

	iter = check_malloc(arlst_iter(fdir));
	fn = NULL;
	iter_ret = 1;
	while (iter_ret > 0)
	{
		tmp_fdir = iter->pip(iter, &iter_ret);
		if (!fn)
			fn = check_malloc(arraylist(tmp_fdir, fdir->size(fdir)));
		else
			fn->push(fn, tmp_fdir);
	}
	free(iter);
	iter = NULL;
	return (fn);
}

static t_arraylist	*ls_first_init(char *opts, t_arraylist *fn, \
									t_arraylist *fdirs)
{
	fn = ls_files(fdirs);
	ls_gen_fdirs_sort(opts, fn);
	return (fn);
}

static void			ls_first_core(char *opts, t_arlst_iter *tmp_arlst)
{
	int				iter_ret;
	t_fdir			*tmp_fdir;

	iter_ret = 1;
	while (iter_ret && (tmp_fdir = tmp_arlst->pip(tmp_arlst, &iter_ret)))
	{
		extract_linfo(tmp_fdir);
		tmp_fdir->expli = tmp_fdir->sl != NULL ? 0 : 1;
		get_file_link(tmp_fdir);
		if (ls_isdir(tmp_fdir->path) || S_ISLNK(tmp_fdir->stats->st_mode))
		{
			if (S_ISLNK(tmp_fdir->stats->st_mode) &&
				ls_isdir(tmp_fdir->sl) && !opts_has_l(opts))
			{
				ft_strdel(&tmp_fdir->sl);
				continue ;
			}
			else if (S_ISLNK(tmp_fdir->stats->st_mode))
				ls_print_sl(opts, tmp_fdir);
		}
		else
			ls_print_l(opts, tmp_fdir, tmp_fdir->info);
		ft_strdel(&tmp_fdir->sl);
	}
	ft_strdel(&tmp_fdir->sl);
}

static void			ls_first_free(t_arraylist *fn, t_arlst_iter *tmp_arlst)
{
	fn->del(fn);
	fn = NULL;
	free(tmp_arlst);
	tmp_arlst = NULL;
}

void				ls_first(char *opts, t_arraylist *fdirs)
{
	t_arraylist		*fn;
	char			*l_queue;
	t_arlst_iter	*tmp_arlst;

	fn = NULL;
	fn = ls_first_init(opts, fn, fdirs);
	if (fn != NULL)
	{
		l_queue = ft_strchr(opts, 'l');
		l_queue ? *l_queue = 'F' : 0;
		tmp_arlst = arlst_iter(fn);
		ft_strchr(opts, 'r') ? tmp_arlst->pip = tmp_arlst->pop : 0;
		ls_l_prepare(opts, fn, false);
		ls_first_core(opts, tmp_arlst);
		fdirs->size(fdirs) > fn->size(fn) ? ft_putchar('\n') : 0;
		ls_first_free(fn, tmp_arlst);
	}
	ls_loop(opts, fdirs, 1);
}
