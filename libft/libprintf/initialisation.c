/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   initialisation.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlegendr <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 14:08:56 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 19:00:04 by rlegendr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_t_printf_2(t_printf *d)
{
	d->bad_conv = -1;
	d->isneg = 0;
	d->nb_zero = 0;
	d->conv = 0;
	d->h = 0;
	d->hh = 0;
	d->l = 0;
	d->ll = 0;
	d->lf = 0;
	d->hash = 0;
	d->zero = 0;
	d->minus = 0;
	d->plus = 0;
	d->space = 0;
	d->point = 0;
	d->size = 0;
	d->accu = 0;
}

void	init_t_printf(t_printf *d)
{
	d->bad_conv = 0;
	d->fatal_error = 0;
	d->size_ans = 0;
	d->ret = 0;
	init_t_printf_2(d);
}

void	init_op_int(t_int *i)
{
	i->nb_long_long = 0;
	i->nb_long = 0;
	i->nb_int = 0;
	i->nb_short = 0;
	i->ans = NULL;
}

void	init_op_uint(t_uint *i)
{
	i->nb_long_long = 0;
	i->nb_long = 0;
	i->nb_int = 0;
	i->nb_short = 0;
	i->ans = NULL;
}
