/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ls_colours.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/29 22:27:25 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/30 17:36:54 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	check_mode(char *to_col, mode_t mode)
{
	(S_ISDIR(mode)) ? ft_printf("%s%s%s", _DIRC, to_col, RESET) : 0;
	(S_ISBLK(mode)) ? ft_printf("%s%s%s", _BLKC, to_col, RESET) : 0;
	(S_ISCHR(mode)) ? ft_printf("%s%s%s", _CHRC, to_col, RESET) : 0;
	(S_ISLNK(mode)) ? ft_printf("%s%s%s", _LNKC, to_col, RESET) : 0;
	(S_ISFIFO(mode)) ? ft_printf("%s%s%s", _FIFC, to_col, RESET) : 0;
	(S_ISSOCK(mode)) ? ft_printf("%s%s%s", _SOCC, to_col, RESET) : 0;
	if (S_ISREG(mode))
	{
		if ((mode & S_IXUSR) || (mode & S_IXGRP) || (mode & S_IXOTH))
		{
			if ((mode & S_ISUID) || (mode & S_ISGID))
			{
				(mode & S_ISUID) ?
				ft_printf("%s%s%s", _UID, to_col, RESET) :
				ft_printf("%s%s%s", _GID, to_col, RESET);
				return ;
			}
			ft_printf("%s%s%s", __EXC, to_col, RESET);
		}
		else
			ft_printf("%s%s", RESET, to_col);
	}
}

void		ls_format_name_c(char *opts, t_fdir *fdirs)
{
	char	*tmp;

	tmp = !getpwuid(fdirs->stats->st_uid) && getgrgid(fdirs->stats->st_gid) ? \
			fdirs->path : fdirs->name;
	check_mode(tmp, fdirs->stats->st_mode);
	if (opts_has_l(opts) && fdirs->sl != NULL)
		ft_printf(" -> %s", fdirs->sl);
	ft_putchar('\n');
}
