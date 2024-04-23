/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:39:02 by cdelamar          #+#    #+#             */
/*   Updated: 2024/03/27 03:58:12 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_min(t_list *stack, int nb)
{
	int		min;
	t_list	*head;

	head = stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if (min > head->index && head->index != nb)
			min = head->index;
	}
	return (min);
}

int	ft_range(t_list *stack, int index)
{
	t_list	*head;
	int		range;

	range = 0;
	head = stack;
	while (head->next)
	{
		if (head->index == index)
			break ;
		range++;
		head = head->next;
	}
	return (range);
}

t_list	*ra_sa_ssa(t_list *stack)
{
	ra(&stack);
	sa(&stack);
	rra(&stack);
	return (stack);
}

t_list	*sa_rra(t_list *stack)
{
	sa(&stack);
	rra(&stack);
	return (stack);
}
