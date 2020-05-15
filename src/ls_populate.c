/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ls_populate.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/28 15:41:26 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/30 01:16:14 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_arraylist			*ls_dirs(char *opts, t_arraylist *fdirs)
{
	t_arraylist		*dirs;
	t_arlst_iter	*iter;
	int				iter_ret;
	t_fdir			*tmp_dir;

	iter = arlst_iter(fdirs);
	dirs = NULL;
	iter_ret = 1;
	while (iter_ret > 0)
	{
		tmp_dir = iter->pip(iter, &iter_ret);
		if (!S_ISDIR(tmp_dir->stats->st_mode))
		{
			if (!ls_isdir(tmp_dir->path))
				continue;
			if (ft_strchr(opts, 'l'))
				continue;
		}
		if (!dirs)
			dirs = check_malloc(arraylist(tmp_dir, fdirs->size(fdirs)));
		else
			dirs->push(dirs, tmp_dir);
	}
	free(iter);
	return (dirs);
}

void				ls_gen_fdirs_sort(char *opts, t_arraylist *fdirs)
{
	if (!fdirs)
		return ;
	if (ft_strchr(opts, 't'))
		fdirs->sort(fdirs, ls_fdir_t_cmp);
	else
		fdirs->sort(fdirs, ls_fdir_cmp);
}

static void			populate_end(DIR *curr_dir, t_arraylist *fdirs, char *opts,
		char *cwd)
{
	closedir(curr_dir);
	ls_gen_fdirs_sort(opts, fdirs);
	ft_strdel(&cwd);
}

t_arraylist			*ls_populate_fdirs(char *opts, t_fdir *tmp_fdir)
{
	t_arraylist		*fdirs;
	DIR				*curr_dir;
	t_dirent		*dir_entry;
	char			*cwd;
	char			*path;

	if (!(curr_dir = opendir(tmp_fdir->path)))
		return (lsperror(tmp_fdir->name));
	cwd = ft_strjoin(tmp_fdir->path, "/");
	fdirs = NULL;
	while ((dir_entry = readdir(curr_dir)) != NULL)
	{
		path = ft_strjoin(cwd, dir_entry->d_name);
		if (!(tmp_fdir = fdir(path)))
		{
			free(path);
			continue ;
		}
		!fdirs ? fdirs = check_malloc(arraylist(tmp_fdir, _DIR_BUF)) :
			fdirs->push(fdirs, tmp_fdir);
		free(path);
		ft_strdel(&(tmp_fdir->sl));
	}
	populate_end(curr_dir, fdirs, opts, cwd);
	return (fdirs);
}
