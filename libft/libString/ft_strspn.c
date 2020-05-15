/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strspn.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: raging <raging@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/16 16:53:28 by raging       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/16 16:58:54 by raging      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(const char *s, const char *charset)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (*(s + j) && *(s + j) == *(charset + i))
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
