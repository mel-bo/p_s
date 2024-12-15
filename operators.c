/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:15:56 by mel-bout          #+#    #+#             */
/*   Updated: 2024/12/14 22:56:24 by mel-bout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_n(stack *s)
{
	node	*tmp;

	if (s->size == 2)
	{
		tmp = s->head;
		s->head->preview = s->tail;
		s->tail->next = s->head;
		s->head->next = NULL;
		s->tail->preview = NULL;
		s->head = s->tail;
		s->tail = tmp;
	}
	else
	{
		tmp = s->head->next;
		s->head->next = tmp->next;
		s->head->preview = tmp;
		tmp->next = s->head;
		tmp->preview = NULL;
		s->head = tmp;
	}
}

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

void	rev_rotate(stack *s)
{
	node	*tmp;

	tmp = s->tail->preview;
	if (s->size == 2)
		swap_n(s);
	else
	{
		s->head->preview = s->tail;
		s->tail->next = s->head;
		s->tail->preview = NULL;
		tmp->next = NULL;
		s->head = s->tail;
		s->tail = tmp;
	}
}

void	push(stack *x, stack *y)
{
	node	*tmp;
	
	if (!y->head)
	{
		y->head = x->head;
		y->tail = x->head;
		x->head = x->head->next;
		x->head->preview = NULL;
		y->head->next = NULL;
	}
	else
	{
		tmp = y->head;
		y->head = x->head;
		x->head = x->head->next;
		if (x->head != NULL)
			x->head->preview = NULL;
		y->head->next = tmp;
		tmp->preview = y->head;
	}
	if (x->head == NULL)
		x->tail = NULL;
	x->size--;
	y->size++;
}
void	rotate_a(stack *a, node *target)
{
	node	*ptr;

	ptr = a->head;
	while (ptr != target)
	{
		if (target->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	rotate_b(stack *b, node *target)
{
	node	*ptr;

	ptr = b->head;
	while (ptr != target)
	{
		if (target->above_median)
			rb(b);
		else
			rrb(b);
	}
}
void	pa(stack *a, stack *b)
{
	push(b, a);
	ft_printf("pa\n");
}

void	pb(stack *a, stack *b)
{
	push(a, b);
	ft_printf("pb\n");
}

void	ra(stack *a)
{
	rotate_n(a);
	ft_printf("ra\n");
}

void	rra(stack *a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}
void	rb(stack *b)
{
	rotate_n(b);
	ft_printf("rb\n");
}

void	rrb(stack *b)
{
	rotate_n(b);
	ft_printf("rrb\n");
}