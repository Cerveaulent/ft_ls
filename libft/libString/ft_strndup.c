/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strndup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/06 16:46:00 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 17:52:39 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	len;
	char	*tmp;

	len = ft_strnlen(s, n) + 1;
	if (!(tmp = (char *)malloc(len)))
		return (NULL);
	tmp[len] = '\0';
	return ((char *)ft_memcpy(tmp, s, len));
}
