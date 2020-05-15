/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   x_arraylist_del.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: raging <raging@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/28 14:10:54 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/05 12:38:02 by raging      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "arraylist.h"

void	x_arraylist_del(t_arraylist *arlst)
{
	free(arlst->x_array);
	free(arlst);
	arlst = NULL;
}
