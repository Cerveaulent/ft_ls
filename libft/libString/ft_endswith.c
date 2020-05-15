/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_endswith.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/30 12:30:37 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/25 09:46:57 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int			ft_endswith(char *end, char *haystack)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(end) - 1;
	j = 0;
	k = ft_strlen(haystack) - 1;
	if (i > k)
		return (-1);
	while (j < i)
	{
		if (end[i - j] == haystack[k - j])
			j++;
		else
			break ;
	}
	return (i == j);
}
