/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 11:34:23 by mel-bout          #+#    #+#             */
/*   Updated: 2024/12/15 21:32:43 by mel-bout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (j == 0 && (s[i][j] == '-' || s[i][j] == '+'))
				j++;
			if (s[i][j] < '0' || s[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	limit(char **tab, stack *a)
{
	int		i;
	long	n;
	
	i = 0;
	while (tab[i])
	{
		n = ft_atol(tab[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (1);
		enqueue(a, n);
		i++;
	}
	return (0);
}

int	check_double(stack *a)
{
	node	*value;
	node	*base;
	
	base = a->tail;
	while (base != NULL)
	{
		value = base->preview;
		while (value != NULL)
		{
			if (base->x == value->x)
				return (1);
			value = value->preview;
		}
		base = base->preview;
	}
	return (0);
}

int	in_order(stack *s)
{
	node	*ptr;
	int		ref_value;

	if (!s->head)
		return (1);
	ptr = s->head;
	ref_value = ptr->x;
	if (s->size > 1)
		ptr = ptr->next;
	while (ptr != NULL)
	{
		if (ptr->x > ref_value)
			ref_value = ptr->x;
		else
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int	parser(char **tab, stack *a)
{
	if (ft_isdigit(tab))
		return (1);
	if (limit(tab, a))
		return (free_stack(a), 1);
	if (check_double(a))
		return (free_stack(a), 1);
	if (in_order(a))
		return (free_stack(a), 1);
	return (0);
}
