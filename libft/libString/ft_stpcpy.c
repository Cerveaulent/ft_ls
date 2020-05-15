/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_stpcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/06 15:45:08 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/10 17:10:15 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stpcpy(char *dst, const char *src)
{
	size_t	len;

	len = ft_strlen(src);
	return (ft_memcpy(dst, src, len + 1) + len);
}
