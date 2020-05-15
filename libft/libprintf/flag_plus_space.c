/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag_plus_space.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 14:15:03 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 14:13:41 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

#define PS d->plus == 1 ? '+' : ' '

char	*flag_plus_space2(char *str, t_printf *d, int i)
{
	if (d->zero == 1)
	{
		if (d->size_ans < d->size)
			str[0] = PS;
		else if (d->size_ans >= d->size)
			str = add_first_char(str, PS, d);
	}
	else
	{
		i = go_to_ans(str, i, d);
		if (i > 0)
			str[--i] = PS;
		else if (i == 0)
			str = add_first_char(str, PS, d);
	}
	return (str);
}

char	*flag_plus_space1(char *str, t_printf *d, int i)
{
	if (d->size && d->accu)
	{
		if (d->size > d->accu)
		{
			if (d->size_ans < d->accu)
				str[d->size - d->accu - 1] = PS;
			else if (d->size_ans >= d->accu)
				str = add_first_char(str, PS, d);
		}
		if (d->size <= d->accu)
			str = add_first_char(str, PS, d);
	}
	else if (d->size)
	{
		str = flag_plus_space2(str, d, i);
	}
	else if (d->accu)
		str = add_first_char(str, PS, d);
	return (str);
}

char	*flag_plus_space(char *str, t_printf *d, int i)
{
	if (d->accu || d->size)
	{
		str = flag_plus_space1(str, d, i);
	}
	else
		str = add_first_char(str, PS, d);
	return (str);
}
