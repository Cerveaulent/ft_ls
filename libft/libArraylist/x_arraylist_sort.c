/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   x_arraylist_sort.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/28 14:11:42 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 14:11:43 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "arraylist.h"

void	x_arraylist_sort(t_arraylist *arlst, int (*cmp)())
{
	size_t		size;
	void		**array;
	size_t		i;
	size_t		j;
	void		*temp;

	size = arlst->size(arlst);
	array = arlst->x_array + arlst->x_first_pos;
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (cmp(array[j], array[j + 1]) > 0)
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
