/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:55:42 by psanger           #+#    #+#             */
/*   Updated: 2023/11/29 13:55:20 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*root;

	root = malloc(sizeof(t_list));
	if (root == NULL)
		return (NULL);
	root->content = content;
	root->next = NULL;
	return (root);
}

void	ft_lstadd_back(t_list **lst, int content)
{
	t_list	*curr;
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return ;
	new->content = content;
	new->next = NULL;
	curr = *lst;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
}

void	ft_lstadd_front(t_list **lst, int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return ;
	new->content = content;
	new->next = *lst;
	*lst = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*curr;

	curr = lst;
	if (lst == NULL)
		return (NULL);
	while (curr->next != NULL)
		curr = curr->next;
	return (curr);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*curr;
	t_list	*temp;

	if (lst == NULL)
		return ;
	curr = *lst;
	while (curr != NULL)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	lst = NULL;
}
