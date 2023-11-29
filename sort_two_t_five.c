/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_t_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:25:02 by psanger           #+#    #+#             */
/*   Updated: 2023/11/28 20:46:40 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **list)
{
	if (is_sorted(list, 2) == 0)
		sa(*list);
	return ;
}

void	sort_three(t_list **list_a)
{
	if (is_sorted(list_a, 3) == 1)
		return ;
	if ((*list_a)->content > (*list_a)->next->content
		&& (*list_a)->content > (*list_a)->next->next->content)
	{
		ra(list_a);
		if (is_sorted(list_a, 3) == 0)
			sa(*list_a);
		return ;
	}
	if ((*list_a)->content < (*list_a)->next->content
		&& (*list_a)->content > (*list_a)->next->next->content)
	{
		rra(list_a);
		return ;
	}
	if ((*list_a)->content < (*list_a)->next->content
		&& (*list_a)->content < (*list_a)->next->next->content)
		rra(list_a);
	if (is_sorted(list_a, 3) == 0)
		sa(*list_a);
	return ;
}

int	find_pos_smallest(t_list **list_a)
{
	int		pos;
	t_list	*curr;
	int		num;

	if (list_a == NULL)
		return (0);
	num = (*list_a)->content;
	curr = *list_a;
	while (curr != NULL)
	{
		if (curr->content < num)
			num = curr->content;
		curr = curr->next;
	}
	curr = *list_a;
	pos = 0;
	while ((curr->content) != num)
	{
		curr = curr->next;
		pos++;
	}
	return (pos);
}

void	push_b_smallest(t_list **list_a, t_list **list_b)
{
	int	pos_smallest;
	int	len;

	while (lst_len(list_a) > 3)
	{
		len = (lst_len(list_a));
		pos_smallest = find_pos_smallest(list_a);
		if (pos_smallest < (len / 2 + len % 2))
		{
			pos_smallest++;
			while (--pos_smallest != 0)
				ra(list_a);
		}
		else
		{
			pos_smallest--;
			while (++pos_smallest != len)
				rra(list_a);
		}
		pb(list_a, list_b);
	}
}

void	sort_five(t_list **list_a, t_list **list_b)
{
	push_b_smallest(list_a, list_b);
	if (lst_len(list_a) == 2)
		reverse_sort_two(list_b);
	sort_three(list_a);
	if (lst_len(list_b) == 2)
		pa(list_a, list_b);
	pa(list_a, list_b);
	return ;
}
