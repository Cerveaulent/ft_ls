/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strisupper.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 02:19:17 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 02:19:30 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_strisupper(const char *s)
{
	char	*s2;

	if (!s || !*s)
		return (0);
	s2 = (char *)s;
	while (*s2 && ft_isupper(*s2))
		s2++;
	return (!*s2 ? 1 : 0);
}
