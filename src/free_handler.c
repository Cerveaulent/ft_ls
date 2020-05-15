/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_handler.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/23 17:46:38 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/30 00:19:42 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void				del_fdir(t_fdir *filedir)
{
	if (filedir->path)
		ft_strdel(&(filedir->path));
	if (filedir->name)
		ft_strdel(&(filedir->name));
	if (filedir->mode)
		ft_strdel(&(filedir->mode));
	if (filedir->stats != NULL)
	{
		free(filedir->stats);
		filedir->stats = NULL;
	}
	if (filedir->sl != NULL)
		ft_strdel(&(filedir->sl));
	if (filedir->info != NULL)
	{
		free(filedir->info);
		filedir->info = NULL;
	}
	if (filedir)
	{
		free(filedir);
		filedir = NULL;
	}
}

void				del_fdir_arlst(t_arraylist *fdirs)
{
	t_arlst_iter	*iter;
	int				iter_ret;
	t_fdir			*tmp_dir;

	if (!fdirs)
		return ;
	iter = arlst_iter(fdirs);
	iter_ret = 1;
	while (iter_ret > 0)
	{
		tmp_dir = iter->pop(iter, &iter_ret);
		if (tmp_dir != NULL)
			del_fdir(tmp_dir);
	}
	free(iter);
	iter = NULL;
	fdirs->del(fdirs);
	fdirs = NULL;
}
