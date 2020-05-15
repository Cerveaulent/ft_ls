/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   arlst_iter.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/28 14:09:48 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 14:09:51 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "arraylist.h"

t_arlst_iter	*arlst_iter(t_arraylist *arlst)
{
	t_arlst_iter	*iter;

	iter = malloc(sizeof(t_arlst_iter));
	if (!iter)
		return (NULL);
	iter->arlst = arlst;
	iter->x_first_pos = arlst->x_first_pos;
	iter->x_last_pos = arlst->x_last_pos;
	iter->x_is_end = 0;
	iter->pop = x_arlst_iter_pop;
	iter->pip = x_arlst_iter_pip;
	return (iter);
}
