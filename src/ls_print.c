/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ls_print.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/28 17:58:19 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/30 07:21:14 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void					ls_print_extended(char *opts, t_fdir *tmp_fdir,
	t_linfo *tmp_info)
{
	if (ls_isdir(tmp_fdir->name) && tmp_fdir->expli == 1)
		return ;
	lstat(tmp_fdir->path, tmp_fdir->stats);
	if (opts_has_l(opts))
		ls_print_l(opts, tmp_fdir, tmp_info);
	else
		ls_format_name_c(opts, tmp_fdir);
}

void					ls_print(char *opts, t_arraylist *fdirs, t_bool state)
{
	t_arlst_iter	*iter;
	int				iter_ret;
	t_fdir			*tmp_fdir;

	if (!fdirs)
		return ;
	if (opts_has_l(opts) && fdirs->x_tru_size > 3 && state)
		ls_l_prepare(opts, fdirs, true);
	else if (opts_has_l(opts))
		ls_l_prepare(opts, fdirs, false);
	iter = arlst_iter(fdirs);
	if (ft_strchr(opts, 'r'))
		iter->pip = iter->pop;
	iter_ret = 1;
	tmp_fdir = NULL;
	while (iter_ret)
	{
		tmp_fdir = iter->pip(iter, &iter_ret);
		get_file_link(tmp_fdir);
		if (grab_entry(opts, tmp_fdir->name))
			ls_print_extended(opts, tmp_fdir, tmp_fdir->info);
	}
	free(iter);
}
