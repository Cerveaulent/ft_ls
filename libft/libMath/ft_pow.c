/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pow.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 01:32:25 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 01:45:08 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

static double	ft_case(double x, int y, double z)
{
	if (y % 2 == 0)
		return (z * z);
	else
		return (y > 0 ? x * z * z : z * z / x);
}

double			ft_pow(double x, int y)
{
	double	z;

	if (y == 0)
		return (1);
	z = ft_pow(x, y / 2);
	return (ft_case(x, y, z));
}
