/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:32:39 by mel-bout          #+#    #+#             */
/*   Updated: 2024/12/15 21:32:07 by mel-bout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_b(stack *a, stack *b, node *cheapest)
{
	node	*ptr_a;
	node	*ptr_b;
	
	ptr_a = a->head;
	ptr_b = b->head;
	while (ptr_a != cheapest && ptr_b != cheapest->target_node)
	{
		rotate_n(a);
		rotate_n(b);
		ft_printf("rr\n");
	}
	get_index(a);
	get_index(b);	
}

void	rev_rotate_a_b(stack *a, stack *b, node *cheapest)
{
	node	*ptr_a;
	node	*ptr_b;
	
	ptr_a = a->head;
	ptr_b = b->head;
	while (ptr_a != cheapest && ptr_b != cheapest->target_node)
	{
		rev_rotate(a);
		rev_rotate(b);
		ft_printf("rrr\n");
	}
	get_index(a);
	get_index(b);	
}

void	push_a_to_b(stack *a, stack *b)
{
	node	*cheapest_node;

	cheapest_node = get_cheapest(a);
	if (cheapest_node->above_median && cheapest_node->above_median)
		rotate_a_b(a, b, cheapest_node);
	else if (!cheapest_node->above_median && !cheapest_node->above_median)
		rev_rotate_a_b(a,b, cheapest_node);
	rotate_a(a, cheapest_node);
	rotate_b(b, cheapest_node->target_node);
	pb(a, b, false);
}

void	push_b_to_a(stack *a, stack *b)
{
	rotate_a(a, b->head->target_node);
	pa(a, b, false);
}

void	min_to_top(stack *a)
{
	node	*min;

	min = get_min_node(a);
	while (a->head != min)
	{
		if (min->above_median)
			ra(a, false);
		else if (!min->above_median)
			rra(a, false);
	}
}