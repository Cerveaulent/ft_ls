/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcspn.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: raging <raging@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 18:07:04 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/16 16:53:39 by raging      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *s, const char *charset)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (*(s + j) && *(s + j) != *(charset + i))
	{
		if (!*(charset + i))
		{
			i = -1;
			j++;
		}
		i++;
	}
	return (j);
}
