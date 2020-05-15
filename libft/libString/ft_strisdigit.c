/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strisdigit.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 02:14:14 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 02:14:37 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_strisdigit(const char *s)
{
	char	*s2;

	if (!s || !*s)
		return (0);
	s2 = (char *)s;
	while (*s2 && ft_isdigit(*s2))
		s2++;
	return (!*s2 ? 1 : 0);
}
