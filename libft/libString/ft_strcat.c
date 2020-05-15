/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/28 01:15:49 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/02 03:28:05 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	size_t	d;
	size_t	s;

	s = ft_strlen(src);
	d = ft_strlen(dst);
	ft_memcpy(dst + d, src, s);
	dst[d + s] = 0;
	return (dst);
}
