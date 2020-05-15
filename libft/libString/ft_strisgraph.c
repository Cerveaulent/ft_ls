/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strisgraph.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 02:14:55 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 02:15:15 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_strisgraph(const char *s)
{
	char	*s2;

	if (!s || !*s)
		return (0);
	s2 = (char *)s;
	while (*s2 && ft_isgraph(*s2))
		s2++;
	return (!*s2 ? 1 : 0);
}
