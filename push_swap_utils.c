/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:17:00 by mel-bout          #+#    #+#             */
/*   Updated: 2024/12/14 23:20:51 by mel-bout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // effacer

void	enqueue(stack *q, int n)
{
	node	*new_node;

	new_node = malloc(sizeof(node));
	if (!new_node)
		return ;
	new_node->x = n;
	new_node->index = 0;
	new_node->preview = NULL;
	new_node->next = NULL;
	if (q->tail != NULL)
	{
		q->tail->next = new_node;
		new_node->preview = q->tail;
	}
	q->tail = new_node;
	q->size++;
	if (q->head == NULL)
		q->head = new_node;
}

void	free_stack(stack *s)
{
		node	*ptr;
		node	*tmp;

		ptr = s->head;
		while (ptr !=NULL)
		{
			tmp = ptr->next;
			free(ptr);
			ptr = tmp;
		}
}
