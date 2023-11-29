/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_quicksort_improoved.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:26:23 by psanger           #+#    #+#             */
/*   Updated: 2023/11/28 13:37:26 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_reverse_sorted(t_list **list_b, int len)
{
	t_list	*curr;
	int		i;

	i = 1;
	curr = *list_b;
	while (curr->next != NULL && i < len)
	{
		if (curr->content < curr->next->content)
			return (0);
		curr = curr->next;
		i++;
	}
	return (1);
}

void	reverse_sort_two(t_list **list_b)
{
	if ((*list_b)->content < (*list_b)->next->content)
		sb(*list_b);
}

void	a_quick(t_list **list_a, t_list **list_b, int len, int median)
{
	int	pushed;
	int	j;

	j = 1;
	pushed = 0;
	median = get_median(list_a, len, 'u');
	if (len == 2)
		sort_two(list_a);
	if (lst_len(list_a) == 3)
		sort_three(list_a);
	if (is_sorted(list_a, len) == 1)
		return ;
	while (pushed != len / 2)
	{
		if ((*list_a)->content < median && ++pushed)
			pb(list_a, list_b);
		else if (j++)
			ra(list_a);
	}
	while (j-- > 1)
		rra(list_a);
	return (a_quick(list_a, list_b, (len - pushed), 0), b_quick(list_a, list_b, pushed, 0));
}

void	b_quick(t_list **list_a, t_list **list_b, int len, int median)
{
	int	pushed;
	int	j;

	j = 1;
	pushed = 0;
	median = get_median(list_b, len, 'l');
	if (len == 2)
		reverse_sort_two(list_b);
	if (is_reverse_sorted(list_a, len) == 1)
	{
		while (len-- > 0)
			pa(list_a, list_b);
		return ;
	}
	while (len / 2 + len % 2 != pushed)
	{
		if ((*list_b)->content >= median && ++pushed)
			pa(list_a, list_b);
		else if (j++)
			rb(list_b);
	}
	while (j-- > 1)
		rrb(list_b);
	return (a_quick(list_a, list_b, pushed, 0), b_quick(list_a, list_b, (len - pushed), 0));
}
