/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ls_print_permissions.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/30 02:00:51 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/30 12:32:03 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_set_rights(char *str, int mode)
{
	(mode & S_IRUSR) ? str[1] = 'r' : (void)str;
	(mode & S_IWUSR) ? str[2] = 'w' : (void)str;
	(mode & S_IXUSR) ? str[3] = 'x' : (void)str;
	if (mode & S_ISUID)
		str[3] = ((mode & S_IXUSR) ? 's' : 'S');
	(mode & S_IRGRP) ? str[4] = 'r' : (void)str;
	(mode & S_IWGRP) ? str[5] = 'w' : (void)str;
	(mode & S_IXGRP) ? str[6] = 'x' : (void)str;
	if (mode & S_ISGID)
		str[6] = ((mode & S_IXGRP) ? 's' : 'S');
	(mode & S_IROTH) ? str[7] = 'r' : (void)str;
	(mode & S_IWOTH) ? str[8] = 'w' : (void)str;
	(mode & S_IXOTH) ? str[9] = 'x' : (void)str;
	if (mode & S_ISVTX)
		str[9] = ((str[9] == '-') ? 'T' : 't');
	str[10] = ' ';
}

char			*ls_print_permissions(int mode, char *link, char *path)
{
	char	*str;

	str = ft_strnew(13);
	ft_strcpy(str, "----------  ");
	(S_ISDIR(mode)) ? str[0] = 'd' : (void)str;
	(S_ISLNK(mode)) ? str[0] = 'l' : (void)str;
	(link) ? str[0] = 'l' : (void)str;
	(S_ISSOCK(mode)) ? str[0] = 's' : (void)str;
	(S_ISFIFO(mode)) ? str[0] = 'p' : (void)str;
	(S_ISCHR(mode)) ? str[0] = 'c' : (void)str;
	(S_ISBLK(mode)) ? str[0] = 'b' : (void)str;
	ls_set_rights(str, mode);
	if ((!link && listxattr(path, NULL, 0, 0x0001) > 0) ||
			(link && listxattr(path, NULL, 0, 0x0001) > 0))
		str[10] = '@';
	ft_putstr(str);
	return (str);
}
