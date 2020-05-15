/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strisalnum.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 01:58:44 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 02:08:30 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_strisalnum(const char *s)
{
	char	*s2;

	if (!s || !*s)
		return (0);
	s2 = (char *)s;
	while (*s2 && ft_isalnum(*s2))
		s2++;
	return (!*s2 ? 1 : 0);
}
