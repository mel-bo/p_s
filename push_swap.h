/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 11:35:29 by mel-bout          #+#    #+#             */
/*   Updated: 2024/12/15 21:30:29 by mel-bout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h> ////

typedef struct	node
{
	int			x;
	int 		index;
	int			cost;
	bool		above_median;
	bool		cheapest;
	struct node *preview;
	struct node	*next;
	struct node	*target_node;
}	node;

typedef struct stack
{
	node	*head;
	node	*tail;
	int		size;
	int 	median;
	
}	stack;

int		parser(char **tab, stack *a);
int		ft_isdigit(char **s);
int		limit(char **tab, stack *a);
int		check_double(stack *a);
int		in_order(stack *s);


void	enqueue(stack *q, int n);
void	free_stack(stack *s);


void	sort_algo(stack *a, stack *b);


void    get_index(stack *s);
void	target_a(stack *a, stack *b);
void	target_b(stack *a, stack *b);
void	cheapest(stack *a);
void	check_cost_a(stack *a, stack *b);


node	*get_cheapest(stack *a);
node	*get_max_node(stack *b);
node	*get_min_node(stack *a);


void	push_a_to_b(stack *a, stack *b);
void	push_b_to_a(stack *a, stack *b);
void	min_to_top(stack *a);
void	rotate_a_b(stack *a, stack *b, node *cheapest);
void	rev_rotate_a_b(stack *a, stack *b, node *cheapest);


void	swap_n(stack *s);
void	rotate_n(stack *s);
void	rev_rotate(stack *s);
void	push(stack *x, stack *y);
void	rotate_a(stack *a, node *target);
void	rotate_b(stack *b, node *target);
void	pa(stack *a, stack *b, bool print);
void	pb(stack *a, stack *b, bool print);
void	ra(stack *a, bool print);
void	rra(stack *a, bool print);
void	rb(stack *b, bool print);
void	rrb(stack *b, bool print);


#endif