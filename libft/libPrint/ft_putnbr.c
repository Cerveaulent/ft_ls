/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/20 17:12:33 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/27 09:33:34 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int	f;

	f = 0;
	if (n == -2147483648)
	{
		n %= 1000000000;
		f = 1;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (f == 1)
	{
		ft_putchar('2');
		f = 0;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + 48);
	}
	else
		ft_putchar(n % 10 + '0');
}
