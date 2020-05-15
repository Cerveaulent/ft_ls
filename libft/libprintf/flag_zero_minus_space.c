/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag_zero_minus_space.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 14:18:53 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 12:21:28 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		go_to_ans(char *str, int i, t_printf *d)
{
	while ((str[i] == ' ' || str[i] == '0') &&
			i < (int)ft_strlen(str) - d->size_ans)
		i++;
	return (i);
}

char	*flag_zero(char *str, int i)
{
	i = -1;
	while (str[++i])
	{
		if (str[i] == ' ')
			str[i] = '0';
	}
	return (str);
}

char	*flag_minus(char *str, t_printf *d, int i, int j)
{
	char	*ans;

	if (!(ans = malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (error("malloc flags minus failed", d));
	if (d->conv == 's')
	{
		while (i < (int)ft_strlen(str) - (d->space + d->size_ans))
			i++;
	}
	else
	{
		while (i < ((int)ft_strlen(str) - ((d->space || d->plus) +
			(d->size_ans < d->accu ? d->accu : d->size_ans))) && str[i] == ' ')
			i++;
	}
	while (str[i])
		ans[j++] = str[i++];
	while (i > j)
		ans[j++] = ' ';
	ans[j] = '\0';
	free(str);
	return (ans);
}

char	*add_minus_char(char *str, t_printf *d)
{
	int		i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (--i >= 0)
		str[i] = '-';
	else
	{
		if (str[0] == '0' && d->size > d->accu)
			str[0] = '-';
		else
			str = add_first_char(str, '-', d);
	}
	return (str);
}

char	*last_flags(char *str, t_printf *d)
{
	if (d->zero == 1)
		str = flag_zero(str, 0);
	if (d->plus == 1 || d->space == 1)
		str = flag_plus_space(str, d, 0);
	if (d->hash == 1 && (d->conv == 'x' ||
				d->conv == 'X' || d->conv == 'p') &&
			!((d->conv == 'x' || d->conv == 'X') && d->nb_zero == 1))
		str = flag_hash_hexa(str, d, 0, 2);
	if (d->hash == 1 && d->conv == 'o' && d->accu == 0)
		str = flag_hash_octale(str, d, 0);
	if (d->isneg == 1)
		str = add_minus_char(str, d);
	if (d->minus == 1)
		str = flag_minus(str, d, 0, 0);
	return (str);
}
