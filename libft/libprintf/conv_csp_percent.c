/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conv_csp_percent.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 14:00:23 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/04 14:50:53 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*op_char(va_list ap, t_printf *d)
{
	char		c;
	char		*ans;

	if (d->bad_conv == -1)
		c = va_arg(ap, int);
	else
		c = d->bad_conv;
	if (!(ans = malloc(sizeof(char) * 2)))
		return (error("malloc op char failed", d));
	ans[0] = c;
	ans[1] = '\0';
	return (ans);
}

char	*op_string(va_list ap, t_printf *d)
{
	char		*str;
	char		*ans;
	int			i;

	i = -1;
	ans = NULL;
	str = va_arg(ap, char*);
	if (str == NULL)
		return (ft_strdup("(null)"));
	if (d->accu == 0)
	{
		if (!(ans = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
			return (error("malloc op string failed", d));
		ans = ft_strcpy(ans, str);
	}
	else
	{
		if (!(ans = (char*)malloc(sizeof(char) * (d->accu + 1))))
			return (error("malloc op string failed", d));
		while (++i < d->accu)
			ans[i] = str[i];
		ans[i] = '\0';
	}
	return (ans);
}

char	*op_pointer(va_list ap, t_printf *d)
{
	void		*str;
	long long	k;
	char		*ans;

	str = va_arg(ap, void*);
	k = (long long)str;
	ans = ft_itoa_printf(k, 16, d);
	return (ans);
}

char	*op_percent(t_printf *d)
{
	char *ans;

	if (!(ans = malloc(sizeof(char) * 2)))
		error("malloc percent failed", d);
	ans[0] = '%';
	ans[1] = '\0';
	return (ans);
}
