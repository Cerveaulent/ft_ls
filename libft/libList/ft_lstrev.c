/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/10 16:52:12 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/10 17:18:04 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **alst)
{
	t_list	*prev;
	t_list	*curr;
	t_list	*next;

	prev = NULL;
	curr = *alst;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*alst = prev;
}
