/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conv_b_tab.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlegendr <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/17 01:55:15 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 07:21:34 by rlegendr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*op_bin_2(va_list ap, t_printf *d, t_uint *i)
{
	if (d->l == 1)
	{
		i->nb_long = va_arg(ap, long);
		i->ans = ft_itoa_printf_u((unsigned long long)i->nb_long, 2, d);
	}
	if (d->ll == 0 && d->l == 0 && d->hh == 0 && d->h == 0)
	{
		i->nb_int = va_arg(ap, int);
		i->ans = ft_itoa_printf_u((unsigned long long)i->nb_int, 2, d);
	}
	if (d->h == 1)
	{
		i->nb_short = (short)va_arg(ap, int);
		i->ans = ft_itoa_printf_u((unsigned long long)i->nb_short, 2, d);
	}
	if (d->hh == 2)
	{
		i->nb_short = (char)va_arg(ap, int);
		i->ans = ft_itoa_printf_u((unsigned long long)i->nb_short, 2, d);
	}
	return (i->ans);
}

char	*op_bin(va_list ap, t_printf *d)
{
	t_uint	i;

	init_op_uint(&i);
	if (d->ll == 2)
	{
		i.nb_long_long = va_arg(ap, long long);
		i.ans = ft_itoa_printf_u((unsigned long long)i.nb_long_long, 2, d);
	}
	return (op_bin_2(ap, d, &i));
}

char	*op_tab(va_list ap, t_printf *d)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = -1;
	tab = va_arg(ap, char**);
	if (tab == NULL)
		return (ft_strnew(0));
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			d->ret += ft_printf("%c", tab[i][j]);
			k = -1;
			while (d->accu > ++k && tab[i][j + 1])
				d->ret += ft_printf(" ");
		}
		j = -2;
		while (d->size > ++j && tab[i + 1])
			d->ret += ft_printf("\n");
	}
	init_t_printf_2(d);
	return (ft_strnew(0));
}
