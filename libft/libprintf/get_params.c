/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_params.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlegendr <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/16 13:00:03 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/25 09:50:33 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_flags(const char *str, int i, t_printf *d)
{
	while (str[i] == '0' || str[i] == ' ' ||
			str[i] == '+' || str[i] == '-' || str[i] == '#')
	{
		if (str[i] == '0')
			d->zero = 1;
		if (str[i] == ' ')
			d->space = 1;
		if (str[i] == '+')
			d->plus = 1;
		if (str[i] == '-')
			d->minus = 1;
		if (str[i] == '#')
			d->hash = 1;
		i++;
	}
	return (i);
}

size_t	get_size_or_accu(const char *str, int i, t_printf *d, int mode)
{
	if (mode == 1)
	{
		d->size = ft_atoi(str + i);
		return (count_digit(d->size));
	}
	if (mode == 2)
	{
		d->accu = ft_atoi(str + i);
		return (count_digit(d->accu));
	}
	return (-1);
}

int		get_lenght(const char *str, int i, t_printf *d)
{
	if (str[i] == 'h' && str[i + 1] == 'h')
		d->hh = 2;
	else if (str[i] == 'h')
		d->h = 1;
	else if (str[i] == 'l' && str[i + 1] == 'l')
		d->ll = 2;
	else if (str[i] == 'l')
		d->l = 1;
	else if (str[i] == 'L')
		d->lf = 1;
	return (d->hh + d->h + d->ll + d->l + d->lf);
}

int		get_params(const char *str, int i, t_printf *d)
{
	if (is_flag(str, i))
		i = get_flags(str, i, d);
	if (str[i] >= '0' && str[i] <= '9')
		i += get_size_or_accu(str, i, d, 1);
	if (str[i] == '.')
	{
		d->point = 1;
		i++;
		if (str[i] >= '0' && str[i] <= '9')
			i += get_size_or_accu(str, i, d, 2);
	}
	if (is_lenght(str, i))
		i += get_lenght(str, i, d);
	if (is_conv(str, i))
		d->conv = str[i];
	else
	{
		d->bad_conv = str[i];
		d->conv = 'c';
	}
	return (i);
}
