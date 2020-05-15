/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conv_dio.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlegendr <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/17 01:42:40 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 01:46:16 by rlegendr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*op_int_2(va_list ap, t_printf *d, t_int *i)
{
	if (d->l == 1)
	{
		i->nb_long = va_arg(ap, long);
		i->ans = ft_itoa_printf((long long)i->nb_long, 10, d);
	}
	if (d->ll == 0 && d->l == 0 && d->hh == 0 && d->h == 0)
	{
		i->nb_int = va_arg(ap, int);
		i->ans = ft_itoa_printf((long long)i->nb_int, 10, d);
	}
	if (d->h == 1)
	{
		i->nb_short = (short)va_arg(ap, int);
		i->ans = ft_itoa_printf((long long)i->nb_short, 10, d);
	}
	if (d->hh == 2)
	{
		i->nb_short = (char)va_arg(ap, int);
		i->ans = ft_itoa_printf((long long)i->nb_short, 10, d);
	}
	return (i->ans);
}

char	*op_int(va_list ap, t_printf *d)
{
	t_int	i;

	init_op_int(&i);
	if (d->ll == 2)
	{
		i.nb_long_long = va_arg(ap, long long);
		if (i.nb_long_long < 0)
		{
			d->plus = 0;
			d->isneg = 1;
		}
		if (i.nb_long_long > 9223372036854775807 ||
				i.nb_long_long < -9223372036854775807)
			i.ans = ft_itoa_printf_u((unsigned long long)i.nb_long_long, 10, d);
		else
			i.ans = ft_itoa_printf(i.nb_long_long, 10, d);
	}
	return (op_int_2(ap, d, &i));
}

char	*op_octal_2(va_list ap, t_printf *d, t_uint *i)
{
	if (d->l == 1)
	{
		i->nb_long = va_arg(ap, long);
		i->ans = ft_itoa_printf_u((unsigned long long)i->nb_long, 8, d);
	}
	if (d->ll == 0 && d->l == 0 && d->hh == 0 && d->h == 0)
	{
		i->nb_int = va_arg(ap, int);
		i->ans = ft_itoa_printf_u((unsigned long long)i->nb_int, 8, d);
	}
	if (d->h == 1)
	{
		i->nb_short = (short)va_arg(ap, int);
		i->ans = ft_itoa_printf_u((unsigned long long)i->nb_short, 8, d);
	}
	if (d->hh == 2)
	{
		i->nb_short = (char)va_arg(ap, int);
		i->ans = ft_itoa_printf_u((unsigned long long)i->nb_short, 8, d);
	}
	return (i->ans);
}

char	*op_octal(va_list ap, t_printf *d)
{
	t_uint	i;

	init_op_uint(&i);
	if (d->ll == 2)
	{
		i.nb_long_long = va_arg(ap, long long);
		i.ans = ft_itoa_printf_u((unsigned long long)i.nb_long_long, 8, d);
	}
	return (op_octal_2(ap, d, &i));
}
