/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strisblank.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 02:12:04 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 02:12:27 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_strisblank(const char *s)
{
	char	*s2;

	if (!s || !*s)
		return (0);
	s2 = (char *)s;
	while (*s2 && ft_isblank(*s2))
		s2++;
	return (!*s2 ? 1 : 0);
}
