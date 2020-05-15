/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ls_get_sl.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/14 20:03:01 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/30 00:53:40 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void			get_file_link(t_fdir *fdir)
{
	char		s[10000];
	ssize_t		link_len;

	link_len = readlink(fdir->path, s, 9999);
	if (link_len < 0)
	{
		fdir->sl = NULL;
		return ;
	}
	s[link_len] = '\0';
	fdir->sl = check_malloc(ft_strdup(s));
}
