/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   accuracy_size.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlegendr <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 14:10:27 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 07:24:07 by rlegendr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*accuracy(char *ans, t_printf *d)
{
	char	*str2;
	char	*tmp;
	int		len_accu;
	int		i;

	tmp = ans;
	i = 0;
	len_accu = d->accu - ft_strlen(ans);
	if (!(str2 = (char*)malloc(sizeof(char) * len_accu + 1)))
		return (error("malloc str2 accuracy failed", d));
	while (i < len_accu && d->conv != 's')
		str2[i++] = '0';
	str2[i] = '\0';
	ans = ft_strjoin(str2, ans);
	free(tmp);
	free(str2);
	return (ans);
}

char	*size(char *ans, t_printf *d)
{
	char	*str2;
	char	*tmp;
	int		len_size;
	int		i;

	tmp = ans;
	i = 0;
	len_size = d->size - ft_strlen(ans);
	if (!(str2 = (char*)malloc(sizeof(char) * len_size + 1)))
		return (error("malloc str2 size failed", d));
	while (i < len_size)
		str2[i++] = ' ';
	str2[i] = '\0';
	ans = ft_strjoin(str2, ans);
	free(tmp);
	free(str2);
	return (ans);
}

char	*accuracy_and_size(char *str, t_printf *d)
{
	if (d->accu && (int)ft_strlen(str) < d->accu)
		str = accuracy(str, d);
	if (d->size && (int)ft_strlen(str) < d->size)
		str = size(str, d);
	return (str);
}
