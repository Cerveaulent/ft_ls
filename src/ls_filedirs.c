/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ls_filedirs.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/28 17:22:32 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/30 00:53:00 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_fdir			*init_fdir(char *given_path, int state)
{
	t_fdir		*curr_fdir;

	curr_fdir = NULL;
	check_prm(given_path);
	curr_fdir = check_malloc(malloc(sizeof(t_fdir)));
	curr_fdir->path = check_malloc(ft_strdup(given_path));
	if (!state && ft_strchr(curr_fdir->path, '/'))
		curr_fdir->name = check_malloc(
			ft_strdup(ft_strrchr(curr_fdir->path, '/') + 1));
	else
		curr_fdir->name = check_malloc(ft_strdup(given_path));
	curr_fdir->stats = check_malloc(malloc(sizeof(struct stat)));
	get_file_link(curr_fdir);
	curr_fdir->mode = NULL;
	ls_get_info(&curr_fdir);
	curr_fdir->expli = 0;
	curr_fdir->stats->st_blocks = 0;
	curr_fdir->stats->st_uid = 0;
	curr_fdir->stats->st_gid = 0;
	curr_fdir->stats->st_mtime = 0;
	curr_fdir->stats->st_mode = 0;
	curr_fdir->stats->st_nlink = 0;
	curr_fdir->stats->st_size = 0;
	curr_fdir->stats->st_rdev = 0;
	return (curr_fdir);
}

static void		ft_strsortarray(size_t size, char **str_array)
{
	size_t		i;
	size_t		j;
	char		*tmp;

	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - i - 1)
		{
			if (ft_strcmp(str_array[j], str_array[j + 1]) > 0)
			{
				tmp = str_array[j];
				str_array[j] = str_array[j + 1];
				str_array[j + 1] = tmp;
			}
		}
	}
}

t_fdir			*fdir(char *given_path)
{
	t_fdir		*curr_fdir;
	int			ret;
	int			ret2;

	curr_fdir = init_fdir(given_path, 0);
	ret = lstat(curr_fdir->path, curr_fdir->stats);
	ret2 = stat(curr_fdir->path, curr_fdir->stats);
	if (ret == -1 && ret2 == -1)
	{
		lsperror(curr_fdir->path);
		del_fdir(curr_fdir);
		return (NULL);
	}
	return (curr_fdir);
}

t_fdir			*direct_fdir(char *given_path, char *opts)
{
	t_fdir			*curr_fdir;
	int				ret;

	if (!given_path)
		return (NULL);
	curr_fdir = NULL;
	curr_fdir = init_fdir(given_path, 1);
	ret = lstat(curr_fdir->path, curr_fdir->stats);
	if (ret == -1)
	{
		lsperror(curr_fdir->path);
		if (curr_fdir)
			del_fdir(curr_fdir);
		return (NULL);
	}
	if (curr_fdir->sl)
		return (direct_fdir_extended_sl(curr_fdir, opts));
	return (curr_fdir);
}

t_arraylist		*get_fdirs_list(int lsize, char **list, char *opts)
{
	int			i;
	t_fdir		*tmp_dir;
	t_arraylist	*fdirs;

	ft_strsortarray((size_t)lsize, list);
	i = -1;
	fdirs = NULL;
	tmp_dir = NULL;
	while (++i < lsize)
	{
		if ((tmp_dir = direct_fdir(list[i], opts)) != NULL)
		{
			tmp_dir->expli = 1;
			if (!fdirs)
				fdirs = check_malloc(arraylist(tmp_dir, lsize));
			else
				fdirs->push(fdirs, tmp_dir);
		}
	}
	if (ft_strchr(opts, 't') && !(ft_strchr(opts, 'l')))
		ls_gen_fdirs_sort(opts, fdirs);
	return (fdirs);
}
