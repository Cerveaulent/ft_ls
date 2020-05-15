/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 05:17:50 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 17:50:09 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	char	*tmp;

	if (!size && ptr)
	{
		if (!(tmp = (char *)malloc(1)))
			return (NULL);
		ft_memdel(&ptr);
		return (tmp);
	}
	if (!(tmp = (char *)malloc(size)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(tmp, ptr, size);
		ft_memdel(&ptr);
	}
	return (tmp);
}
