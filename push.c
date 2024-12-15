/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:06:51 by mel-bout          #+#    #+#             */
/*   Updated: 2024/12/15 18:10:56 by mel-bout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	pa(stack *a, stack *b, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pa\n");
}

void	pb(stack *a, stack *b, bool print)
{
	push(a, b);
	if (!print)
		ft_printf("pb\n");
}
