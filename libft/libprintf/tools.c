/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlegendr <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 13:55:53 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 08:20:59 by rlegendr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_first_char(char *str, char c, t_printf *d)
{
	char	*ans;
	int		i;

	ans = NULL;
	i = -1;
	if (!(ans = malloc(sizeof(char) * ft_strlen(str) + 2)))
		return (error("malloc first char failed", d));
	ans[0] = c;
	while (str[++i])
		ans[i + 1] = str[i];
	ans[i + 1] = '\0';
	free(str);
	return (ans);
}

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
