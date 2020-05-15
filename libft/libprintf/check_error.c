/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_error.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlegendr <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 14:20:59 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 15:57:16 by rlegendr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags_error(t_printf *d)
{
	if (d->accu != 0 || d->minus == 1)
		d->zero = 0;
	if (d->plus == 1)
		d->space = 0;
	if (d->conv == 'c' || d->conv == '%')
	{
		d->accu = 0;
		d->space = 0;
		d->plus = 0;
	}
	if (d->plus == 1 && d->conv == 'u')
		d->plus = 0;
	if (d->space == 1 && d->conv == 'u')
		d->space = 0;
	if (d->nb_zero == 1)
		d->hash = 0;
	if (d->conv == 'f')
		d->accu = 6;
	if (d->conv == 'p')
		d->hash = 1;
}

char	*error(char *str, t_printf *d)
{
	d->fatal_error = 1;
	return (ft_strdup(str));
}
