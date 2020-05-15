/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ls_filedirs_re.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/07 19:25:44 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/30 00:46:08 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_fdir		*direct_fdir_extended_sl(t_fdir *curr_fdir, char *opts)
{
	t_fdir	*tmp;
	char	*tmp_str;

	tmp = NULL;
	tmp_str = NULL;
	tmp_str = check_malloc(ft_strjoin("/", curr_fdir->sl));
	tmp = (curr_fdir->name[0] == '/') ? \
		direct_fdir(tmp_str, opts) : 		\
		fdir(curr_fdir->path);
	ft_strdel(&tmp->path);
	tmp->path = check_malloc(ft_strdup(curr_fdir->path));
	del_fdir(curr_fdir);
	get_file_link(tmp);
	ft_strdel(&tmp_str);
	return (tmp);
}
