/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putfloat1.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 14:21:58 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 08:59:40 by rlegendr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		g_nblen;
int		g_intlen;
int		g_isneg;
int		g_ret;
int		g_loop;

static void		filldouble(double n, char *ret)
{
	int			i;

	i = g_isneg ? g_intlen : g_intlen - 1;
	while (i > g_isneg ? 1 : 0)
	{
		ret[i - (!g_isneg ? 1 : 2)] = (long)n % 10 + '0';
		n /= 10;
		i--;
	}
	if (g_isneg)
		ret[0] = '-';
}

static void		putrest(long double n, int prec, char *ret)
{
	int			i;
	long long	r;

	i = 1;
	while (i <= prec + 1)
	{
		n *= 10;
		r = (long long)n;
		ret[g_intlen + i - 1] = (char)(r % 10) + '0';
		if (i == prec + 1)
			g_ret = (r % 10) >= 5 ? 1 : 0;
		i++;
	}
	if (prec > 0)
		ret[g_intlen - 1] = '.';
}

static void		solve(int i, long double n, int prec, char *ret)
{
	if (n < 10)
	{
		putrest(n - (int)n, prec, ret);
		ret[i + (!g_loop ? 0 : g_isneg)] = (long double)n + '0';
		ret[++i + (!g_loop ? 0 : g_isneg)] = '.';
		if (g_isneg)
			ret[0] = '-';
	}
	else
	{
		g_loop += 1;
		putrest(n - (long)n, prec, ret);
		filldouble(n, ret);
	}
}

char			*ft_putfloat(long double n, int prec)
{
	int			i;
	char		*ret;

	ret = NULL;
	g_loop = 0;
	g_nblen = prec + ft_countdigits(n);
	g_intlen = ft_countdigits((long)n);
	g_nblen += g_intlen < 3 ? 1 : 0;
	ret = init_ret(ret, g_nblen);
	i = 0;
	if (n < 0)
	{
		g_isneg = 1;
		n = -n;
		i++;
	}
	else
		g_isneg = 0;
	solve(i, n, prec, ret);
	ret[g_nblen] = '\0';
	put_ret(ret, g_ret);
	return (ret);
}

char			*op_float(va_list ap, t_printf *d)
{
	char		*ans;
	double		n;

	ans = NULL;
	n = va_arg(ap, long double);
	ans = ft_putfloat((long double)n, d->accu);
	return (ans);
}
