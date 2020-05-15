/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conv_uxx.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlegendr <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/17 01:43:31 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 01:43:42 by rlegendr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*op_u_int_2(va_list ap, t_printf *d, t_uint *i)
{
	if (d->l == 1)
	{
		i->nb_long = va_arg(ap, long);
		i->ans = ft_itoa_printf_u((unsigned long long)i->nb_long, 10, d);
	}
	if (d->ll == 0 && d->l == 0 && d->hh == 0 && d->h == 0)
	{
		i->nb_int = va_arg(ap, int);
		i->ans = ft_itoa_printf_u((unsigned long long)i->nb_int, 10, d);
	}
	if (d->h == 1)
	{
		i->nb_short = (short)va_arg(ap, int);
		i->ans = ft_itoa_printf_u((unsigned long long)i->nb_short, 10, d);
	}
	if (d->hh == 2)
	{
		i->nb_short = (char)va_arg(ap, int);
		i->ans = ft_itoa_printf_u((unsigned long long)i->nb_short, 10, d);
	}
	return (i->ans);
}

char	*op_u_int(va_list ap, t_printf *d)
{
	t_uint	i;

	init_op_uint(&i);
	if (d->ll == 2)
	{
		i.nb_long_long = va_arg(ap, long long);
		i.ans = ft_itoa_printf_u((unsigned long long)i.nb_long_long, 10, d);
	}
	return (op_u_int_2(ap, d, &i));
}

char	*op_hexa_2(va_list ap, t_printf *d, t_uint *i)
{
	if (d->l == 1)
	{
		i->nb_long = va_arg(ap, long);
		i->ans = ft_itoa_printf_u((unsigned long long)i->nb_long, 16, d);
	}
	if (d->ll == 0 && d->l == 0 && d->hh == 0 && d->h == 0)
	{
		i->nb_int = va_arg(ap, int);
		i->ans = ft_itoa_printf_u((unsigned long long)i->nb_int, 16, d);
	}
	if (d->h == 1)
	{
		i->nb_short = (short)va_arg(ap, int);
		i->ans = ft_itoa_printf_u((unsigned long long)i->nb_short, 16, d);
	}
	if (d->hh == 2)
	{
		i->nb_short = (char)va_arg(ap, int);
		i->ans = ft_itoa_printf_u((unsigned long long)i->nb_short, 16, d);
	}
	return (d->conv == 'X' ? ft_strcapitalize(i->ans) : i->ans);
}

char	*op_hexa(va_list ap, t_printf *d)
{
	t_uint	i;

	init_op_uint(&i);
	if (d->ll == 2)
	{
		i.nb_long_long = va_arg(ap, long long);
		i.ans = ft_itoa_printf_u((unsigned long long)i.nb_long_long, 16, d);
	}
	return (op_hexa_2(ap, d, &i));
}
