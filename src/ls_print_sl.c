/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ls_print_sl.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/30 02:23:29 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/30 06:48:50 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_print_sl(char *opts, t_fdir *curr_sl)
{
	ft_strdel(&(curr_sl->name));
	curr_sl->name = (char *)check_malloc(ft_strdup(curr_sl->path));
	lstat(curr_sl->path, curr_sl->stats);
	if (opts_has_l(opts) && S_ISLNK(curr_sl->stats->st_mode))
		ls_print_l(opts, curr_sl, curr_sl->info);
	else
		ls_print_extended(opts, curr_sl, curr_sl->info);
}
