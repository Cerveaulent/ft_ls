/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag_hash.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlegendr <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/15 08:43:24 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 13:50:57 by rlegendr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flag_hash_octale(char *str, t_printf *d, int i)
{
	while (str[i] == ' ')
		i++;
	if (--i >= 0)
		str[i] = '0';
	else
		str = add_first_char(str, '0', d);
	return (str);
}

char	*flag_hash_hexa_2(char *str, int j, char *ans, t_printf *d)
{
	if (str[0] == '0' && str[1] == '0' && j == 1)
		str[1] = ans[1];
	else if (str[0] == '0' && str[1] != '0' && j == 1)
	{
		str[0] = ans[1];
		str = add_first_char(str, ans[0], d);
	}
	else if (str[0] != '0' && str[1] != ans[1])
		str = add_first_char(str, ans[j], d);
	return (str);
}

char	*flag_hash_hexa(char *str, t_printf *d, int i, int j)
{
	char	*ans;

	ans = d->conv == 'X' ? "0X" : "0x";
	while (str[i] == ' ')
		i++;
	while (--j >= 0)
	{
		if (--i >= 0)
		{
			if (d->conv == 'x' || d->conv == 'X' || d->conv == 'p')
				str[i] = ans[j];
		}
		else
		{
			if (d->size > d->accu)
				str = flag_hash_hexa_2(str, j, ans, d);
			else if (d->size <= d->accu)
			{
				str = add_first_char(str, ans[1], d);
				str = add_first_char(str, ans[0], d);
				break ;
			}
		}
	}
	return (str);
}
