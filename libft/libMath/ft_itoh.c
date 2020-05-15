/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoh.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 02:48:12 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/22 23:21:57 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t	hexlen(int nb)
{
	size_t	i;

	i = 1;
	while (nb != 0)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

static char		*itoh_putbase(int nb, int i, char *ret, char *base)
{
	if (nb > 15)
		ret[i] = base[nb % 16];
	else
		ret[i] = base[nb];
	return (ret);
}

/*
** need to free hbase ;-p
*/

char			*ft_itoh(int n)
{
	int		i;
	char	*hex;
	char	*hbase;

	i = 0;
	hbase = ft_strdup("0123456789abcdef");
	hex = malloc(sizeof(char) * hexlen(n));
	if (!n)
		while (i < 2)
			hex[i++] = '0';
	if (n <= 15 && n != 0)
	{
		hex[i] = hbase[n % 16];
		hex[++i] = '0';
		i++;
		n /= 16;
	}
	while (n != 0)
	{
		hex = itoh_putbase(n, i++, hex, hbase);
		n /= 16;
	}
	hex[++i] = '\0';
	return (ft_strrev(hex));
}
