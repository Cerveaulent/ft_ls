/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr_bs_fd.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 02:36:49 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 03:29:12 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_bs_fd(char const *s, int fd)
{
	char	*s2;

	if (!s || !fd)
		return ;
	s2 = (char *)s;
	while (*s2)
	{
		if (ft_isprint(*s2))
			ft_putchar_fd(*s2, fd);
		else
		{
			ft_putchar_fd('\\', fd);
			if (*s2 == '0')
				ft_putchar_fd('0', fd);
			ft_putstr_fd(ft_itoh(*s2), fd);
		}
		s2++;
	}
	ft_putstr_fd("\\00", fd);
}
