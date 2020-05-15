/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoinfree.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/28 13:12:40 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/30 04:46:17 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinfree(char *s1, char *s2, int a, int b)
{
	size_t	tlen;
	char	*ret;

	tlen = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(ret = (char *)malloc(sizeof(char) * tlen)))
		return (NULL);
	ret = ft_strcpy(ret, s1);
	ret = ft_strcat(ret, s2);
	if (s1 == s2 && (a || b))
	{
		free(s1);
		return (ret);
	}
	if (a)
		free(s1);
	if (b)
		free(s2);
	return (ret);
}
