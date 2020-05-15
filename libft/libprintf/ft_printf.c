/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlegendr <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/21 03:53:28 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 07:31:09 by rlegendr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*op_dispatch(va_list ap, t_printf *d)
{
	if (d->conv == 'c')
		return (op_char(ap, d));
	if (d->conv == 's')
		return (op_string(ap, d));
	if (d->conv == 'p')
		return (op_pointer(ap, d));
	if (d->conv == 'd' || d->conv == 'i')
		return (op_int(ap, d));
	if (d->conv == 'o')
		return (op_octal(ap, d));
	if (d->conv == 'u')
		return (op_u_int(ap, d));
	if (d->conv == 'x' || d->conv == 'X')
		return (op_hexa(ap, d));
	if (d->conv == 'f')
		return (op_float(ap, d));
	if (d->conv == '%')
		return (op_percent(d));
	if (d->conv == 'b')
		return (op_bin(ap, d));
	if (d->conv == 'T')
		return (op_tab(ap, d));
	return (ft_strdup("error"));
}

int		parsing(const char *str, va_list ap, int i, t_printf *d)
{
	char *ans;

	ans = NULL;
	i = get_params(str, i, d);
	if (d->bad_conv != -1)
		ans = op_char(ap, d);
	else
		ans = op_dispatch(ap, d);
	check_flags_error(d);
	d->size_ans = ft_strlen(ans);
	ans = accuracy_and_size(ans, d);
	ans = last_flags(ans, d);
	d->ret += ft_putstr(ans);
	free(ans);
	init_t_printf_2(d);
	return (str[i] == '\0' ? i : i + 1);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	t_printf	d;

	init_t_printf(&d);
	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		while (format[i] != '%' && format[i])
			d.ret += ft_putchar(format[i++]);
		if (format[i])
		{
			if (format[i] == '%')
				i = parsing(format, ap, ++i, &d);
		}
	}
	va_end(ap);
	return (d.fatal_error == 0 ? d.ret : -1);
}
