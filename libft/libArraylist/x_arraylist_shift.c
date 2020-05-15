/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   x_arraylist_shift.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/28 14:11:26 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 14:11:28 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "arraylist.h"

void	x_arraylist_shift(t_arraylist *arlst, void *elem)
{
	if (arlst->x_first_pos == 0)
		arlst->resize(arlst, arlst->x_resbuf);
	arlst->x_array[--arlst->x_first_pos] = elem;
}
