/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:57:49 by psanger           #+#    #+#             */
/*   Updated: 2023/11/21 19:06:27 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *list_a)
{
	int	temp;

	if (list_a->next == NULL || list_a == NULL)
		return ;
	temp = list_a->content;
	list_a->content = list_a->next->content;
	list_a->next->content = temp;
	write(1, "sa\n", 3);
}

void	sb(t_list *list_b)
{
	int	temp;

	if (list_b->next == NULL || list_b == NULL)
		return ;
	temp = list_b->content;
	list_b->content = list_b->next->content;
	list_b->next->content = temp;
	write(1, "sb\n", 3);
}

void	ss(t_list *list_a, t_list *list_b)
{
	sa(list_a);
	sb(list_b);
}

void	pa(t_list **list_a, t_list **list_b)
{
	t_list	*temp;
	int		content;
	t_list	*new;

	if (list_b == NULL)
		return ;
	content = (*list_b)->content;
	temp = (*list_b)->next;
	free(*list_b);
	*list_b = temp;
	new = malloc(sizeof(t_list));
	if (new == NULL)
		return ;
	new->content = content;
	new->next = *list_a;
	*list_a = new;
	write(1, "pa\n", 3);
}

void	pb(t_list **list_a, t_list **list_b)
{
	t_list	*temp;
	int		content;
	t_list	*new;

	if (list_a == NULL)
		return ;
	content = (*list_a)->content;
	temp = (*list_a)->next;
	free(*list_a);
	*list_a = temp;
	new = malloc(sizeof(t_list));
	if (new == NULL)
		return ;
	new->content = content;
	new->next = *list_b;
	*list_b = new;
	write(1, "pb\n", 3);
}
