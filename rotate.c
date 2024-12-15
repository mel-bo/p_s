/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:02:46 by mel-bout          #+#    #+#             */
/*   Updated: 2024/12/15 21:32:55 by mel-bout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_n(stack *s)
{
	node	*tmp;
	
	tmp = s->head->next;
	if (s->size == 2)
		swap_n(s);
	else
	{
		s->tail->next = s->head;
		s->head->preview = s->tail;
		s->head->next = NULL;
		tmp->preview = NULL;
		s->tail = s->head;
		s->head = tmp;
	}
}

void	ra(stack *a, bool print)
{
	rotate_n(a);
	if (!print)
		ft_printf("ra\n");
}

void	rb(stack *b, bool print)
{
	rotate_n(b);
	if (!print)
		ft_printf("rb\n");
}

void	rotate_a(stack *a, node *target)
{
	node	*ptr;

	ptr = a->head;
	while (ptr != target)
	{
		if (target->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	rotate_b(stack *b, node *target)
{
	node	*ptr;

	ptr = b->head;
	while (ptr != target)
	{
		if (target->above_median)
			rb(b, false);
		else
			rrb(b, false);
	}
}
