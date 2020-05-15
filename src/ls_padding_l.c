/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ls_padding_l.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/14 18:15:48 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/30 07:29:59 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_print_sp_left(char *s, size_t sp)
{
	sp += 1;
	while (--sp > ft_strlen(s))
		ft_putchar(' ');
	ft_putstr(s);
	ft_putchar(' ');
}

void	ls_print_sp_right(char *s, size_t sp)
{
	ft_putstr(s);
	sp += 1;
	while (--sp > ft_strlen(s))
		ft_putchar(' ');
	ft_putstr("  ");
}

void	ls_print_left(char *s, size_t sp)
{
	sp += 1;
	while (--sp > ft_strlen(s))
		ft_putchar(' ');
	ft_putstr(s);
}

void	ls_print_right(char *s, size_t sp)
{
	ft_putstr(s);
	sp += 1;
	while (--sp > ft_strlen(s))
		ft_putchar(' ');
}

void	ls_prtparent(char *s)
{
	char			*ret;
	unsigned long	i;

	if (ft_strstr(s, "//"))
	{
		i = 0;
		ret = check_malloc(ft_strnew(ft_strlen(s)));
		while (++i < ft_strlen(s))
			ret[i - 1] = s[i];
		ret[i] = '\0';
		ft_printf("%s:\n", ret);
		free(ret);
		return ;
	}
	ft_printf("%s:\n", s);
}
