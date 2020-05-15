/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isinf.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 01:22:52 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 01:28:31 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int	ft_isinf(double x)
{
	int	i;

	x == (1.0 / 0.0) ? i = 1 : 0;
	x == (-1.0 / 0.0) ? i = -1 : 0;
	return (i);
}
