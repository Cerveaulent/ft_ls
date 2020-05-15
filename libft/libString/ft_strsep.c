/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsep.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/06 16:39:50 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 17:54:01 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsep(char **stringp, const char *delim)
{
	char	*begin;
	char	*end;

	if (!(begin = *stringp))
		return (NULL);
	end = begin + ft_strcspn(begin, delim);
	if (*end)
	{
		*end++ = '\0';
		*stringp = end;
	}
	else
		*stringp = NULL;
	return (begin);
}
