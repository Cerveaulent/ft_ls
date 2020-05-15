/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   opts.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/28 12:33:23 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/30 17:32:34 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_bool	opts_has_l(char *opts)
{
	return (ft_strchr(opts, 'F') || ft_strchr(opts, 'l'));
}

int		check_prm(char *prm)
{
	if (!prm)
		return (1);
	if (!(*prm))
	{
		ft_putendl_fd(_EXEC, 2);
		ft_putendl_fd(": No such file or directory", 2);
		exit(1);
	}
	return (1);
}

int		isopt(char *s, char *opts)
{
	if (!ft_strcmp(s, "--"))
		return (0);
	if (s[0] == '-' && s[1] != '\0')
	{
		checkopts(s + 1, opts);
		return (1);
	}
	return (0);
}

int		parse_opts(char **opts, int prmrange, char **prm)
{
	int	i;

	i = 1;
	while (i < prmrange && isopt(prm[i], *opts) && check_prm(prm[i]))
		*opts = ft_strjoinfree(*opts, prm[i++] + 1, 1, 0);
	checkopts(*opts, *opts);
	if (i < prmrange && !ft_strcmp(prm[i], "--"))
		i++;
	return (i);
}
