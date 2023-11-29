/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operators.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:58:02 by psanger           #+#    #+#             */
/*   Updated: 2023/11/21 19:06:40 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list	**list_a)
{
	int		content;
	t_list	*temp;

	if (*list_a == NULL || (*list_a)->next == NULL)
		return ;
	temp = (*list_a)->next;
	content = (*list_a)->content;
	free(*list_a);
	*list_a = temp;
	ft_lstadd_back(list_a, content);
	write(1, "ra\n", 3);
}

void	rb(t_list	**list_b)
{
	int		content;
	t_list	*temp;

	if (*list_b == NULL || (*list_b)->next == NULL)
		return ;
	temp = (*list_b)->next;
	content = (*list_b)->content;
	free(*list_b);
	*list_b = temp;
	ft_lstadd_back(list_b, content);
	write(1, "rb\n", 3);
}

void	rr(t_list	**list_a, t_list **list_b)
{
	ra(list_a);
	rb(list_b);
}
