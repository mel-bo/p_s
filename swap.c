/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:02:04 by mel-bout          #+#    #+#             */
/*   Updated: 2024/12/14 23:02:26 by mel-bout         ###   ########.fr       */
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
