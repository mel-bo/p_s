/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:26:29 by mel-bout          #+#    #+#             */
/*   Updated: 2024/12/15 21:32:15 by mel-bout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_index(stack *s)
{
	node	*ptr;
	int		i;
	
	if (!s->head)
		return ;
	i = 0;
	ptr = s->head;
	s->median = s->size / 2;
	while (ptr != NULL)
	{
		ptr->index = i;
		if (ptr->index <= s->median)
			ptr->above_median = true;
		else
			ptr->above_median = false;
		i++;
		ptr = ptr->next;
	}
}

void	target_a(stack *a, stack *b)
{
	node	*ptr_a;
	node	*ptr_b;
	node	*target;
	int		target_index;

	ptr_a = a->head;
	while (ptr_a != NULL)
	{
		target_index = INT_MIN;
		ptr_b = b->head;
		while (ptr_b != NULL)
		{
			if (ptr_b->x < ptr_a->x && ptr_b->x > target_index)
			{
				target_index = ptr_b->x;
				target = ptr_b;
			}
			ptr_b = ptr_b->next;
		}
		if (target_index == INT_MIN)
			ptr_a->target_node = get_max_node(b);
		else
			ptr_a->target_node = target;
		ptr_a = ptr_a->next;
	}
}

void	cheapest(stack *a)
{
	node	*ptr;
	node	*cheapest_node;
	int		cheapest;

	if (!a->head)
		return ;
	ptr = a->head;
	cheapest = ptr->cost;
	cheapest_node = ptr;
	while (ptr != NULL)
	{
		if (ptr->cost < cheapest)
		{
			cheapest = ptr->cost;
			cheapest_node = ptr;
		}
		ptr = ptr->next;
	}
	cheapest_node->cheapest = true;
}

void	check_cost_a(stack *a, stack *b)
{
	node	*ptr;

	ptr = a->head;
	while (ptr != NULL)
	{
		ptr->cost = ptr->index;
		if (!ptr->above_median)
			ptr->cost = a->size - ptr->index;
		if (ptr->target_node->above_median)
			ptr->cost += ptr->target_node->index;
		else if (!ptr->target_node->above_median)
			ptr->cost += b->size - ptr->target_node->index;
		ptr = ptr->next;
	}
}

void	target_b(stack *a, stack *b)
{
	node	*ptr_a;
	node	*ptr_b;
	int		index_value;

	ptr_b = b->head;
	while (ptr_b != NULL)
	{
		ptr_a = a->head;
		index_value = INT_MAX;
		while (ptr_a != NULL)
		{
			if (ptr_a->x > ptr_b->x && ptr_a->x < index_value)
			{
				index_value = ptr_a->x;
				ptr_b->target_node = ptr_a;
			}
			ptr_a = ptr_a->next;
		}
		if (index_value == INT_MAX)
			ptr_b->target_node = get_min_node(a);
		ptr_b = ptr_b->next;
	}
}
