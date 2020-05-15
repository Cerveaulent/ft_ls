/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ls_print_l.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/29 13:59:57 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/30 08:52:17 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_xattr(char *opts, char *path, char *namebuf)
{
	char			*tmp;
	ssize_t			ret;
	ssize_t			size;
	ssize_t			curr_len;
	ssize_t			tot;

	namebuf = ft_strnew(9999);
	if ((ret = listxattr(path, namebuf, 9999, 0x0001)) > 0
		&& ft_strchr(opts, '@'))
	{
		size = 0;
		tot = 0;
		tmp = namebuf;
		while (tot < ret)
		{
			curr_len = ft_strlen(tmp) + 1;
			size = getxattr(path, tmp, NULL, 9999, 0, 0x0001);
			if (size >= 0)
				ft_printf("\t%s\t   %ld\n", tmp, size);
			tmp += curr_len;
			tot += curr_len;
			curr_len = ft_strlen(tmp) + 1;
		}
	}
	ft_strdel(&namebuf);
}

static void		ls_print_time(time_t *clock)
{
	char	*tmp;

	tmp = ctime(clock);
	write(1, tmp + 4, 7);
	if (*clock > time(NULL))
		write(1, tmp + 19, 5);
	else if (*clock > (time(NULL) - C_OFFSET))
		write(1, tmp + 11, 5);
	else
		write(1, tmp + 19, 5);
	ft_putchar(' ');
}

static void		ls_print_size(t_linfo *info, t_stat *stats)
{
	char	*max;
	char	*min;
	char	*m;

	max = NULL;
	min = NULL;
	m = NULL;
	if (S_ISCHR(stats->st_mode) || S_ISBLK(stats->st_mode))
	{
		ls_print_left((max = ft_lltoa(major(stats->st_rdev))),
			info->major_spacing);
		ft_putstr(", ");
		ls_print_sp_left((min = ft_lltoa(minor(stats->st_rdev))),
			info->minor_spacing);
		ft_strdel(&min);
		ft_strdel(&max);
	}
	else
	{
		ls_print_sp_left((m = ft_lltoa(stats->st_size)),
			info->size_spacing);
		ft_strdel(&m);
	}
}

void			ls_print_l(char *opts, t_fdir *fdir, t_linfo *tmp_info)
{
	char	*tmp1;
	char	*tmp2;
	char	*tmp3;

	if (!opts_has_l(opts))
		return (ls_format_name_c(opts, fdir));
	fdir->mode = check_malloc(
		(tmp1 = ls_print_permissions(fdir->stats->st_mode, fdir->sl,
		fdir->path)));
	ls_print_sp_left((tmp2 = ft_itoa(fdir->stats->st_nlink)),
		tmp_info->link_spacing);
	ft_strdel(&tmp2);
	ls_print_sp_right((tmp2 = conv_uid(fdir->stats->st_uid)),
		tmp_info->user_spacing);
	getpwuid(fdir->stats->st_uid) == NULL ? ft_strdel(&tmp2) : 0;
	ls_print_sp_right((tmp2 = conv_gid(fdir->stats->st_gid)),
		tmp_info->group_spacing);
	getgrgid(fdir->stats->st_gid) == NULL ? ft_strdel(&tmp2) : 0;
	ls_print_size(tmp_info, fdir->stats);
	ls_print_time(&fdir->stats->st_mtime);
	ls_format_name_c(opts, fdir);
	tmp3 = NULL;
	if (ft_strchr(tmp1, '@'))
		print_xattr(opts, fdir->path, tmp3);
}
