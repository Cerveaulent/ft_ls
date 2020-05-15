/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   itoa_base_ft_printf.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlegendr <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 13:57:52 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 08:23:32 by rlegendr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_printf_2(long long num, int base, char *str)
{
	int					i;
	int					rest;

	i = 0;
	rest = 0;
	while (num != 0)
	{
		rest = num % base;
		str[i++] = (rest > 9) ? (rest - 10) + 'a' : rest + '0';
		num /= base;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}

char	*ft_itoa_printf(long long value, int base, t_printf *d)
{
	long long			num;
	char				*ans;

	num = value;
	if (num == 0)
	{
		d->nb_zero = 1;
		if (d->accu == 0 && d->point == 1)
			return (ft_strnew(0));
		return (ft_strdup("0"));
	}
	if (num < 0)
	{
		d->plus = 0;
		d->isneg = 1;
		num = -num;
	}
	if ((ans = (char *)malloc(sizeof(char) * 65)) == NULL)
		return (error("malloc itoa printf failed", d));
	ans = ft_itoa_printf_2(num, base, ans);
	return (ans);
}

char	*ft_itoa_printf_u_2(unsigned long long num, int base, char *str)
{
	int					i;
	unsigned long long	rest;

	i = 0;
	rest = 0;
	while (num != 0)
	{
		rest = num % base;
		str[i++] = (rest > 9) ? (rest - 10) + 'a' : rest + '0';
		num /= base;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}

char	*ft_itoa_printf_u(
		unsigned long long value, int base, t_printf *d)
{
	char				*ans;

	if (value == 0)
	{
		d->nb_zero = 1;
		if (d->accu == 0 && d->point == 1 && !(d->conv == 'o' && d->hash == 1))
			return (ft_strnew(0));
		return (ft_strdup("0"));
	}
	if ((ans = (char *)malloc(sizeof(char) * 65)) == NULL)
		return (error("malloc itoa printf failed", d));
	ans = ft_itoa_printf_u_2(value, base, ans);
	return (ans);
}
