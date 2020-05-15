/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/28 01:15:49 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 17:23:13 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*d;
	char	*s;
	size_t	i;
	size_t	len;

	len = 0;
	d = dst;
	s = (char *)src;
	while (d[len] && len < size)
		len++;
	i = len;
	while (s[len - i] && size > len + 1)
	{
		d[len] = s[len - i];
		len++;
	}
	if (i < size)
		d[len] = '\0';
	return (ft_strlen(src) + i);
}
