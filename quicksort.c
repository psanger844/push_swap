/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_quicksort_improoved.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:26:23 by psanger           #+#    #+#             */
/*   Updated: 2023/11/29 15:14:07 by psanger          ###   ########.fr       */
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

void	a_quick(t_list **l_a, t_list **l_b, int len, int median)
{
	int	p;
	int	j;

	j = 1;
	p = 0;
	median = get_median(l_a, len, 'u');
	if (len == 2)
		sort_two(l_a);
	if (lst_len(l_a) == 3)
		sort_three(l_a);
	if (is_sorted(l_a, len) == 1)
		return ;
	while (p != len / 2)
	{
		if ((*l_a)->content < median && ++p)
			pb(l_a, l_b);
		else if (j++)
			ra(l_a);
	}
	while (j-- > 1)
		rra(l_a);
	return (a_quick(l_a, l_b, (len - p), 0), b_quick(l_a, l_b, p, 0));
}

void	b_quick(t_list **l_a, t_list **l_b, int len, int median)
{
	int	p;
	int	j;

	j = 1;
	p = 0;
	median = get_median(l_b, len, 'l');
	if (len == 2)
		reverse_sort_two(l_b);
	if (is_reverse_sorted(l_a, len) == 1)
	{
		while (len-- > 0)
			pa(l_a, l_b);
		return ;
	}
	while (len / 2 + len % 2 != p)
	{
		if ((*l_b)->content >= median && ++p)
			pa(l_a, l_b);
		else if (j++)
			rb(l_b);
	}
	while (j-- > 1)
		rrb(l_b);
	return (a_quick(l_a, l_b, p, 0), b_quick(l_a, l_b, (len - p), 0));
}
