/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   x_arraylist_push.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/28 14:11:03 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 14:11:04 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "arraylist.h"

void	x_arraylist_push(t_arraylist *arlst, void *elem)
{
	if (arlst->x_last_pos == arlst->x_tru_size - 1)
		arlst->resize(arlst, arlst->x_resbuf);
	arlst->x_array[++arlst->x_last_pos] = elem;
}
