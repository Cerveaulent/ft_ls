/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strccount.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/10 17:20:16 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/10 17:28:35 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strccount(const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*(s + i))
		if (*(s + i++) == c)
			j++;
	return (j);
}
