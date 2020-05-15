/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lltoa.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/22 22:38:52 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/07/22 23:22:08 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countn(long long n)
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

static char		*ft_lltoa_case(char *str, int neg, int i, long long n)
{
	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
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

char			*ft_lltoa(long long n)
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
	return (ft_lltoa_case(str, neg, ind, n));
}
