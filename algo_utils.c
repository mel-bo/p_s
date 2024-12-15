// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   algo_utils.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mel-bout <mel-bout@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/11/29 16:23:36 by mel-bout          #+#    #+#             */
// /*   Updated: 2024/12/09 00:24:38 by mel-bout         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "push_swap.h"

node	*get_cheapest(stack *a)
{
	node	*ptr;

	if (!a->head)
		return (NULL);
	ptr = a->head;
	while (ptr != NULL)
	{
		if (ptr->cheapest)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

node	*get_max_node(stack *b)
{
	node	*ptr;
	node	*max_node;
	int		max_value;
	
	if (!b->head)
		return (NULL);
	ptr = b->head;
	max_value = ptr->x;
	while (ptr != NULL)
	{
		if (ptr->x > max_value)
		{
			max_value = ptr->x;
			max_node = ptr;
		}
		ptr = ptr->next;
	}
	return (max_node);
}

node	*get_min_node(stack *a)
{
	node	*ptr;
	node	*min_node;
	int		min_value;

	if (!a->head)
		return (NULL);
	ptr = a->head;
	min_value = ptr->x;
	min_node = ptr;
	while (ptr != NULL)
	{
		if (ptr->x < min_value)
		{
			min_value = ptr->x;
			min_node = ptr;
		}
		ptr = ptr->next;
	}
	return (min_node);
}
