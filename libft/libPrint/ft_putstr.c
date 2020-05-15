/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 13:30:42 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/27 09:28:37 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char const *s)
{
	int	len;

	if (!s)
		return (-1);
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}
