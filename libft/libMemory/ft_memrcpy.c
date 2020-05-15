/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memrcpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 15:53:24 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/31 23:58:06 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrcpy(void *dst, const void *src, size_t n)
{
	while (n--)
		*((char *)dst + n) = *((char *)src + n);
	return (dst);
}
