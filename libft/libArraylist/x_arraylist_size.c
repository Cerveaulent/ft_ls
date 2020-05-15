/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   x_arraylist_size.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/28 14:11:35 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 14:11:36 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "arraylist.h"

size_t	x_arraylist_size(t_arraylist *arlst)
{
	return ((arlst->x_last_pos - arlst->x_first_pos) + 1);
}
