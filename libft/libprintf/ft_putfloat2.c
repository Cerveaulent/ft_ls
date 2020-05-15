/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putfloat2.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 14:22:10 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 08:59:44 by rlegendr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		put_ret(char *ret, int g_ret)
{
	int		i;

	i = 0;
	while (ret[i + 1])
		i++;
	while (g_ret)
	{
		if (ret[i] == '9')
			ret[i] = '0';
		else
		{
			ret[i] += 1;
			break ;
		}
		i--;
		if (ret[i] == '.')
			i--;
	}
}

char		*init_ret(char *ret, int g_nblen)
{
	if (!(ret = (char *)malloc(g_nblen + 1)))
		return (NULL);
	ft_bzero(ret, (size_t)g_nblen);
	return (ret);
}
