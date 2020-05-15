/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ls_isdir.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/14 18:24:48 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/30 00:54:05 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int					ls_isdir(char *path)
{
	DIR				*tmp_dir;

	if (!(tmp_dir = opendir(path)))
		return (0);
	closedir(tmp_dir);
	return (1);
}
