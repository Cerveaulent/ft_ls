/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 02:43:10 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/10 18:07:14 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char	*check_byte(uint_fast64_t *l)
{
	char	*cp;
	short	i;

	i = -1;
	cp = (char *)l;
	if (!*cp)
		return (cp);
	while (++i < 7)
		if (!*++cp)
			return (cp);
	return (NULL);
}

size_t		ft_strlen(const char *s)
{
	uint64_t	*l;
	uint64_t	i;
	const char	*cp;

	cp = s;
	if (s == NULL)
		return (0);
	while ((uint64_t)cp & (sizeof(*l) - 1))
		if (!*cp++)
			return (--cp - s);
	l = (uint64_t *)cp;
	while (1)
	{
		i = *l;
		if ((i - QWORD_LBITS) & QWORD_HBITS)
			if ((cp = check_byte(l)))
				return (cp - s);
		++l;
	}
}
