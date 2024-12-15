/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:25:18 by mel-bout          #+#    #+#             */
/*   Updated: 2024/12/15 21:32:36 by mel-bout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(stack *s)
{
	if (s->head->x > s->tail->x)
	{
		swap_n(s);
		ft_printf("sa\n");
	}	
}

void	mini_sort(stack *s)
{
	if (s->head->x > s->tail->x && s->head->x > s->head->next->x)
	{
		rotate_n(s);
		ft_printf("ra\n");
	}
	else if (s->tail->x < s->head->x && s->tail->x < s->head->next->x)
	{
		rev_rotate(s);
		ft_printf("rra\n");
	}
	if (s->head->x > s->head->next->x)
	{
		swap_n(s);
		ft_printf("sa\n");
	}
}

void	push_a_init(stack *a, stack *b)
{
	get_index(a);
	get_index(b);
	target_a(a, b);
	cheapest(a);
	check_cost_a(a, b);
}

void	push_b_init(stack *a, stack *b)
{
	get_index(a);
	get_index(b);
	target_b(a, b);
}

void	sort_algo(stack *a, stack *b)
{
	if (a->size == 1)
		return ;
	else if (a->size == 2)
		sort_2(a);
	else if (a->size == 3)
		mini_sort(a);
	else if (a->size > 3)
	{
		pb(a, b, false);
		if (a->size > 3)
			pb(a, b, false);
		while (a->size > 3)
		{
			push_a_init(a, b);
			push_a_to_b(a, b);
		}
		mini_sort(a);
		while (b->head != NULL)
		{
			push_b_init(a, b);
			push_b_to_a(a, b);
		}
		get_index(a);
		min_to_top(a);
	}
}
