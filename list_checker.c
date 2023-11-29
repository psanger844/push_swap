/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:11:45 by psanger           #+#    #+#             */
/*   Updated: 2023/11/20 15:27:21 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int		i;
	long	num;
	int		minus;

	i = 0;
	num = 0;
	minus = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == '\f' || str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * minus);
}

int	duplicate(t_list **list_a, int new_int)
{
	t_list	*curr;

	curr = *list_a;
	while (curr != NULL)
	{
		if (curr->content == new_int)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	checker(t_list	**list_a, char *argv, int first)
{
	int		i;
	long	new_int;

	i = 0;
	new_int = ft_atol(argv);
	if (argv[i] == '+' || argv[i] == '-')
		i++;
	while (argv[i] != '\0')
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return (0);
		i++;
	}
	if (new_int > INT_MAX || new_int < INT_MIN)
		return (0);
	if (first == 0)
		if (duplicate(list_a, new_int) == 0)
			return (0);
	return (1);
}
