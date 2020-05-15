/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printbits.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/28 18:34:33 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/25 09:48:46 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void				ft_printbits(size_t const size, void const *const ptr)
{
	unsigned char	*b;
	unsigned char	byte;
	int				i;
	int				j;

	i = size - 1;
	b = (unsigned char *)ptr;
	while (i >= 0)
	{
		j = 7;
		while (j >= 0)
		{
			byte = (b[i] >> j) & 1;
			ft_putchar(byte);
			j--;
		}
		i--;
	}
}
