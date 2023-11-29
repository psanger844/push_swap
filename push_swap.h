/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:50:42 by psanger           #+#    #+#             */
/*   Updated: 2023/11/29 15:19:55 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "LIBFT/libft.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

// list_funktions

t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, int content);
void	ft_lstadd_front(t_list **lst, int content);
void	free_lists(t_list **list_a, t_list **list_b);
void	ft_lstclear(t_list **lst);
int		lst_len(t_list **list_a);

// Operationen

void	sa(t_list *list_a);
void	sb(t_list *list_b);
void	ss(t_list *list_a, t_list *list_b);
void	pa(t_list **list_a, t_list **list_b);
void	pb(t_list **list_a, t_list **list_b);
void	ra(t_list	**list_a);
void	rb(t_list	**list_b);
void	rra(t_list **list_a);
void	rrb(t_list **list_b);
void	rrr(t_list **list_a, t_list **list_b);

// list_checker

int		checker(t_list	**list_a, char *argv, int first);
int		duplicate(t_list **list_a, int new_int);
long	ft_atol(const char *str);

// sort small

void	sort_small(t_list **list_a, t_list **list_b);

void	sort_two(t_list **list);
void	reverse_sort_two(t_list **list_b);

void	sort_three(t_list **list_a);

void	sort_five(t_list **list_a, t_list **list_b);
int		find_pos_smallest(t_list **list_a);

// is_sorted

int		is_sorted(t_list **list_a, int len);
int		is_reverse_sorted(t_list **list_b, int len);

// quicksort

void	a_quick(t_list **list_a, t_list **list_b, int len, int median);
void	b_quick(t_list **list_a, t_list **list_b, int len, int median);

// median

int		get_median(t_list **list_a, int len, char u_l);
int		get_median_pt2(t_list **list_a, int median, int len, char u_p);

#endif
