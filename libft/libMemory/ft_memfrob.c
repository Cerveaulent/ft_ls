/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memfrob.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/06 15:07:53 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 17:13:00 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

/*
** Note: this  function  is not a proper encryption routine as the XOR constant
** is fixed, and is suitable only for hiding strings.
*/

void	*memfrob(void *s, size_t n)
{
	char	*s_ptr;

	s_ptr = (char *)s;
	while (n > 0)
		*s_ptr++ ^= 42;
	return (s);
}
