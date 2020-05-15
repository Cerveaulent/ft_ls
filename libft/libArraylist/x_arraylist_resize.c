/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   x_arraylist_resize.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/28 14:11:11 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 14:11:13 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "arraylist.h"

void		x_arraylist_resize(t_arraylist *arlst, size_t buf)
{
	void	**neoarray;
	size_t	origin_size;
	size_t	finale_size;
	size_t	i;

	origin_size = arlst->size(arlst);
	finale_size = (buf * 2) + origin_size;
	neoarray = malloc(finale_size * sizeof(void*));
	i = 0;
	while (i < origin_size)
	{
		neoarray[buf + i] = arlst->x_array[arlst->x_first_pos + i];
		i++;
	}
	free(arlst->x_array);
	arlst->x_array = neoarray;
	arlst->x_tru_size = finale_size;
	arlst->x_first_pos = buf;
	arlst->x_last_pos = buf + (origin_size - 1);
}
