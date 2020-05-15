/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools2.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlegendr <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/16 15:21:02 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/25 09:51:33 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_conv(const char *str, int i)
{
	if (str[i] == 'c' || str[i] == 's' || str[i] == 'p' || str[i] == 'd' ||
			str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'x' ||
			str[i] == 'X' || str[i] == 'f' || str[i] == '%' || str[i] == 'b' ||
			str[i] == 'T')
		return (1);
	return (0);
}

int		is_flag(const char *str, int i)
{
	if (str[i] == '0' || str[i] == ' ' || str[i] == '+' ||
			str[i] == '-' || str[i] == '#')
		return (1);
	return (0);
}

int		is_lenght(const char *str, int i)
{
	if (str[i] == 'h' || str[i] == 'l' || str[i] == 'L')
		return (1);
	return (0);
}

size_t	ft_countdigits(long n)
{
	size_t	i;

	i = 1;
	n < 0 ? i++ : 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int		count_digit(int digit)
{
	int		i;

	i = 1;
	while ((digit /= 10))
		i++;
	return (i);
}
