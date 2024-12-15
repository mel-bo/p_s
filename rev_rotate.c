/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:05:04 by mel-bout          #+#    #+#             */
/*   Updated: 2024/12/15 18:10:47 by mel-bout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	rra(stack *a, bool print)
{
	rev_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(stack *b, bool print)
{
	rotate_n(b);
	if (!print)
		ft_printf("rrb\n");
}
