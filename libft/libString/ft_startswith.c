/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_startswith.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/30 12:15:44 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/25 09:47:55 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int			ft_startswith(char *start, char *haystack)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(start);
	if (ft_strlen(haystack) < j)
		return (-1);
	while (start[i])
	{
		if (start[i] == haystack[i])
			i++;
		else
			break ;
	}
	return (i == j);
}
