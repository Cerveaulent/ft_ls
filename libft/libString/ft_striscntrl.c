/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_striscntrl.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 02:13:15 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 02:13:43 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_striscntrl(const char *s)
{
	char	*s2;

	if (!s || !*s)
		return (0);
	s2 = (char *)s;
	while (*s2 && ft_iscntrl(*s2))
		s2++;
	return (!*s2 ? 1 : 0);
}
