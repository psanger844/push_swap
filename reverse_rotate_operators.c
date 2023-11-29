/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operators.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:29:02 by psanger           #+#    #+#             */
/*   Updated: 2023/11/21 19:06:44 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **list_a)
{
	t_list	*last;
	t_list	*curr;

	if (*list_a == NULL || (*list_a)->next == NULL)
		return ;
	last = ft_lstlast(*list_a);
	ft_lstadd_front(list_a, last->content);
	curr = *list_a;
	while (curr->next->next != NULL)
		curr = curr->next;
	free(curr->next);
	curr->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_list **list_b)
{
	t_list	*last;
	t_list	*curr;

	if (*list_b == NULL || (*list_b)->next == NULL)
		return ;
	last = ft_lstlast(*list_b);
	ft_lstadd_front(list_b, last->content);
	curr = *list_b;
	while (curr->next->next != NULL)
		curr = curr->next;
	free(curr->next);
	curr->next = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(t_list **list_a, t_list **list_b)
{
	rra(list_a);
	rrb(list_b);
}
