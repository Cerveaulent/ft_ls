/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   x_arlst_iter_pop.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/28 14:10:44 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 14:10:46 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "arraylist.h"

void	*x_arlst_iter_pop(struct s_arlst_iter *iter, int *ret)
{
	if (iter->x_is_end)
	{
		*ret = -1;
		return (NULL);
	}
	if (iter->x_first_pos == iter->x_last_pos)
	{
		iter->x_is_end = 1;
		*ret = 0;
		return (iter->arlst->x_array[iter->x_last_pos]);
	}
	*ret = 1;
	return (iter->arlst->x_array[iter->x_last_pos--]);
}
