/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ls_cmp_fdir.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/22 13:51:40 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/30 00:20:03 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int					ls_fdir_cmp(t_fdir *fd1, t_fdir *fd2)
{
	return (ft_strcmp(fd1->name, fd2->name));
}

int					ls_fdir_t_cmp(t_fdir *fd1, t_fdir *fd2)
{
	if (fd1->stats->st_mtime < fd2->stats->st_mtime)
		return (1);
	else if (fd1->stats->st_mtime == fd2->stats->st_mtime)
		return (ft_strcmp(fd1->name, fd2->name));
	else
		return (0);
}
