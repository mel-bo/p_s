/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:10:42 by mel-bout          #+#    #+#             */
/*   Updated: 2024/12/15 21:32:47 by mel-bout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	call_split(char *arg, stack *a)
{
	char	**tab;
	
	tab = ft_split(arg, ' ');
	if (parser(tab, a))
		return (ft_free(tab), 1);
	ft_free(tab);
	return (0);
}
void	init_queue(stack *s)
{
	s->head = NULL;
	s->tail = NULL;
	s->size = 0;
	s->median = 0;
}
#include <stdio.h>
int	main(int argc, char **argv)
{
	stack	a;
	stack	b;

	init_queue(&a);
	init_queue(&b);
	if (argc < 2 || argv[1][0] == '\0')
		return (ft_printf("Error1\n"), 1);
	else if (argc == 2)
	{
		if (call_split(argv[1], &a))
			return (ft_printf("Error2\n"), 1);
	}
	else if (parser((argv + 1), &a))
		return (ft_printf("Error3\n"), 1);
	sort_algo(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
