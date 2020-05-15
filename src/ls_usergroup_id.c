/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ls_usergroup_id.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/29 13:13:23 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/08 17:18:52 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

char				*conv_uid(uid_t uid)
{
	struct passwd	*pw;

	return (((pw = getpwuid(uid)) == NULL) ? ft_itoa(uid) : pw->pw_name);
}

char				*conv_gid(uid_t gid)
{
	struct group	*gp;

	return (((gp = getgrgid(gid)) == NULL) ? ft_itoa(gid) : gp->gr_name);
}
