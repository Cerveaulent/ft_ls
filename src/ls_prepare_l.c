/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ls_prepare_l.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/14 18:22:58 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/30 17:47:42 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static unsigned int	ls_size_size(t_linfo *info, t_stat *stats)
{
	unsigned int	tmp_minor;
	unsigned int	tmp_major;

	if (S_ISCHR(stats->st_mode) || S_ISBLK(stats->st_mode))
	{
		tmp_minor = count_dozen(minor(stats->st_rdev));
		if (info->minor_spacing < tmp_minor)
			info->minor_spacing = tmp_minor;
		tmp_major = count_dozen(major(stats->st_rdev));
		if (info->major_spacing < tmp_major)
			info->major_spacing = tmp_major;
		return (tmp_minor + tmp_major + 4);
	}
	return (count_dozen(stats->st_size));
}

void				extract_linfo(t_fdir *fdir)
{
	static u_int32_t	tmp1;
	static size_t		tmp2;
	static size_t		tmp3;
	static u_int32_t	tmp4;

	tmp1 = !tmp1 ? 0 : tmp1;
	tmp2 = !tmp2 ? 0 : tmp2;
	tmp3 = !tmp3 ? 0 : tmp3;
	tmp4 = !tmp4 ? 0 : tmp4;
	if (tmp1 <= count_dozen(fdir->stats->st_nlink))
		tmp1 = count_dozen(fdir->stats->st_nlink);
	if (tmp2 <= ft_strlen(conv_uid(fdir->stats->st_uid)))
		tmp2 = ft_strlen(conv_uid(fdir->stats->st_uid));
	if (tmp3 <= ft_strlen(conv_gid(fdir->stats->st_gid)))
		tmp3 = ft_strlen(conv_gid(fdir->stats->st_gid));
	if (tmp4 <= ls_size_size(fdir->info, fdir->stats))
		tmp4 = ls_size_size(fdir->info, fdir->stats);
	fdir->info->link_spacing = tmp1;
	fdir->info->user_spacing = tmp2;
	fdir->info->group_spacing = tmp3;
	fdir->info->size_spacing = tmp4;
}

static void			ls_l_prepare_check_sl(t_fdir *tmp_fdir)
{
	if (tmp_fdir->sl != NULL)
	{
		lstat(tmp_fdir->path, tmp_fdir->stats);
		ft_strdel(&tmp_fdir->sl);
	}
}

/*
** Boolean state to know
** if print total or not
*/

void				ls_l_prepare(char *opts, t_arraylist *fdirs, t_bool state)
{
	t_arlst_iter	*iter;
	int				iter_ret;
	t_fdir			*tmp_fdir;
	u_int32_t		file_count;
	u_int64_t		total;

	total = 0;
	file_count = 0;
	iter = arlst_iter(fdirs);
	iter_ret = 1;
	while (iter_ret && (tmp_fdir = iter->pip(iter, &iter_ret)))
	{
		lstat(tmp_fdir->path, tmp_fdir->stats);
		ls_l_prepare_check_sl(tmp_fdir);
		if (grab_entry(opts, tmp_fdir->name) && ++file_count)
		{
			extract_linfo(tmp_fdir);
			total += tmp_fdir->stats->st_blocks;
		}
	}
	free(iter);
	((total || file_count) && state) ? ls_print_total(total) : 0;
	(ft_strchr(opts, 'F') != NULL) ? (*(ft_strchr(opts, 'F')) = 'l') : 0;
}

void				ls_get_info(t_fdir **fdir)
{
	if (!((*fdir)->info = (t_linfo *)malloc(sizeof(t_linfo))))
		return ;
	(*fdir)->info->user_spacing = 0;
	(*fdir)->info->minor_spacing = 0;
	(*fdir)->info->major_spacing = 0;
	(*fdir)->info->size_spacing = 0;
	(*fdir)->info->group_spacing = 0;
	(*fdir)->info->link_spacing = 0;
}
