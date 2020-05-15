/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 16:30:38 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/22 22:38:02 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countn(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char		*ft_itoa_case(char *str, int neg, int i, int n)
{
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (neg == 1)
	{
		n *= -1;
		str[0] = '-';
	}
	while (--i >= neg)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	int		neg;
	char	*str;
	size_t	ind;

	neg = 0;
	ind = ft_countn(n);
	if (n < 0)
	{
		neg++;
		ind++;
	}
	if (!(str = malloc(sizeof(char) * ++ind)))
		return (NULL);
	str[--ind] = '\0';
	return (ft_itoa_case(str, neg, ind, n));
}
