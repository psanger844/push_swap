/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:49:54 by psanger           #+#    #+#             */
/*   Updated: 2023/11/29 15:34:09 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_argument(char **argument)
{
	int	i;

	i = 0;
	while (argument[i] != NULL)
		i++;
	while (i >= 0)
	{
		free(argument[i]);
		i--;
	}
	free(argument);
}

int	make_list_a(t_list **list_a, char **argv, int i)
{
	if (checker(list_a, argv[i], 1) == 0)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	*list_a = ft_lstnew(ft_atol(argv[i]));
	i++;
	while (argv[i] != NULL)
	{
		if (checker(list_a, argv[i], 0) == 0)
		{
			write(1, "ERROR\n", 6);
			ft_lstclear(list_a);
			return (0);
		}
		ft_lstadd_back(list_a, ft_atol(argv[i]));
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*list_a;
	t_list	*list_b;
	char	**arguments;

	list_b = ft_lstnew(0);
	i = 0;
	arguments = NULL;
	if (argc <= 1)
		return (0);
	if (argc == 2)
		arguments = ft_split(argv[1], ' ');
	if (argc > 2)
	{
		arguments = argv;
		i = 1;
	}
	if (make_list_a(&list_a, arguments, i) == 0)
		return (0);
	if (argc == 2)
		ft_free_argument(arguments);
	sort_small(&list_a, &list_b);
	ft_lstclear(&list_a);
	ft_lstclear(&list_b);
	return (0);
}
