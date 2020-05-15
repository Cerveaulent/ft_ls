/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_basename.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/06 16:23:03 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 16:32:25 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_basename(const char *path)
{
	char	*fn;

	fn = ft_strrchr(path, '/');
	return (fn ? fn + 1 : (char *)path);
}
