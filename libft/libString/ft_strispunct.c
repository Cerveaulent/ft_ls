/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strispunct.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 02:17:14 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 02:17:30 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_strispunct(const char *s)
{
	char	*s2;

	if (!s || !*s)
		return (0);
	s2 = (char *)s;
	while (*s2 && ft_ispunct(*s2))
		s2++;
	return (!*s2 ? 1 : 0);
}
