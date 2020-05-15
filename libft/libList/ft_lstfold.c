/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstfold.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 14:54:41 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/31 23:32:41 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstfold(t_list *lst, void *(*f)(void *, void *, size_t))
{
	void	*new;

	if (lst)
	{
		new = lst->content;
		lst = lst->next;
		while (lst)
		{
			new = (f)(new, lst->content, lst->content_size);
			lst = lst->next;
		}
		return (new);
	}
	return (NULL);
}
