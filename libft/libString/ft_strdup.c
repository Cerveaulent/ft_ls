/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/21 10:12:09 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/10 18:12:17 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*cpy;

	if (s1 == NULL)
		return (NULL);
	if (!(cpy = malloc(sizeof(*s1) * (ft_strlen((char *)s1) + 1))))
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		cpy[i] = s1[i];
	cpy[i] = '\0';
	return (cpy);
}
