/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:53:16 by psanger           #+#    #+#             */
/*   Updated: 2023/11/29 15:30:12 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list **list_a, int len)
{
	t_list	*curr;
	int		i;

	i = 0;
	curr = *list_a;
	while (curr->next != NULL && i < len)
	{
		if (curr->content > curr->next->content)
			return (0);
		curr = curr->next;
		i++;
	}
	return (1);
}

int	lst_len(t_list **list_a)
{
	t_list	*curr;
	int		i;

	if (list_a == NULL)
		return (0);
	curr = *list_a;
	i = 0;
	while (curr != NULL)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}

int	get_median_pt2(t_list **list_a, int median, int len, char u_l)
{
	t_list	*curr2;
	int		temp;
	int		i;

	curr2 = *list_a;
	temp = 0;
	i = 0;
	while (curr2 != NULL && i < len)
	{
		if (curr2->content < median)
			temp--;
		if (curr2->content > median)
			temp++;
		curr2 = curr2->next;
		i++;
	}
	if ((temp == 0 || temp == -1) && u_l == 'u')
		return (1);
	if ((temp == 0 || temp == -1) && u_l == 'l')
		return (1);
	return (0);
}

int	get_median(t_list **list_a, int len, char u_l)
{
	t_list	*curr1;
	int		median;
	int		i;

	curr1 = *list_a;
	median = 0;
	i = 0;
	while (curr1 != NULL && i <= len)
	{
		median = curr1->content;
		if (get_median_pt2(list_a, median, len, u_l) == 1)
			return (median);
		curr1 = curr1->next;
		i++;
	}
	return (median);
}

void	sort_small(t_list **list_a, t_list **list_b)
{
	int		len;

	len = lst_len(list_a);
	if (is_sorted(list_a, len) == 1)
		return ;
	if (len <= 2)
	{
		sort_two(list_a);
		return ;
	}
	if (len <= 3)
	{
		sort_three(list_a);
		return ;
	}
	if (len <= 5)
	{
		sort_five (list_a, list_b);
		return ;
	}
	a_quick(list_a, list_b, len, 0);
}
