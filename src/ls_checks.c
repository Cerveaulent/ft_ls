/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ls_checks.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/28 12:45:02 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/15 20:35:42 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void		*lsperror(char *s)
{
	if (!s)
		return (NULL);
	ft_putstr_fd(_EXEC, 2);
	write(2, ": ", 2);
	perror(s);
	return (NULL);
}

void		*check_malloc(void *ret)
{
	if (ret == NULL)
	{
		lsperror(NULL);
		exit(1);
	}
	return (ret);
}

void		checkopts(char *opts, char *to_free)
{
	while (ft_strchr(_LS_OPTS, *opts) && *opts != '\0')
		opts++;
	if (*opts != '\0')
	{
		ft_putstr_fd(_EXEC, 2);
		ft_putstr_fd(": invalid option -- '", 2);
		ft_putchar_fd(*opts, 2);
		ft_putstr_fd("'\nusage: ", 2);
		ft_putstr_fd(_EXEC, 2);
		ft_putstr_fd(" [-", 2);
		ft_putstr_fd(_LS_OPTS, 2);
		ft_putstr_fd("] [file ...]\n", 2);
		free(to_free);
		exit(2);
	}
}

int			isdots(char *s)
{
	if (!ft_strcmp(".", s) || !ft_strcmp("..", s))
		return (1);
	if (!ft_strcmp("./", s) || !ft_strcmp("../", s))
		return (1);
	return (0);
}

int			grab_entry(char *opts, char *s)
{
	if (*s != '.' || ft_strstr(s, "./"))
		return (1);
	if (ft_strchr(opts, 'a'))
		return (1);
	if (ft_strchr(opts, 'A') && !isdots(s))
		return (1);
	return (0);
}
