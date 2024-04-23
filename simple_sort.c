/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:38:59 by cdelamar          #+#    #+#             */
/*   Updated: 2024/03/27 03:11:55 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_list	*sort_three(t_list *stack)
{
	t_list	*head;
	int		min;
	int		next_min;

	head = stack;
	min = ft_min(stack, -1);
	next_min = ft_min(stack, min);
	if (head->index == min && head->next->index != next_min)
		stack = ra_sa_ssa(stack);
	else if (head->index == next_min)
	{
		if (head->next->index == min)
			sa(&stack);
		else
			rra(&stack);
	}
	else
	{
		if (head->next->index == min)
			ra(&stack);
		else
			stack = sa_rra(stack);
	}
	return (stack);
}

static t_stack	sort_four(t_stack aetb)
{
	int	range;

	if (ft_sorted(aetb.stack_a))
		return (aetb);
	range = ft_range(aetb.stack_a, ft_min(aetb.stack_a, -1));
	if (range == 1)
		ra(&aetb.stack_a);
	else if (range == 2)
	{
		ra(&aetb.stack_a);
		ra(&aetb.stack_a);
	}
	else if (range == 3)
		rra(&aetb.stack_a);
	if (ft_sorted(aetb.stack_a))
		return (aetb);
	pb(&aetb.stack_a, &aetb.stack_b);
	aetb.stack_a = sort_three(aetb.stack_a);
	pa(&aetb.stack_a, &aetb.stack_b);
	return (aetb);
}

static t_stack	sort_five(t_stack aetb)
{
	int	range;

	range = ft_range(aetb.stack_a, ft_min(aetb.stack_a, -1));
	if (range == 1)
		ra(&aetb.stack_a);
	else if (range == 2)
	{
		ra(&aetb.stack_a);
		ra(&aetb.stack_a);
	}
	else if (range == 3)
	{
		rra(&aetb.stack_a);
		rra(&aetb.stack_a);
	}
	else if (range == 4)
		rra(&aetb.stack_a);
	if (ft_sorted (aetb.stack_a))
		return (aetb);
	pb(&aetb.stack_a, &aetb.stack_b);
	aetb = sort_four(aetb);
	pa(&aetb.stack_a, &aetb.stack_b);
	return (aetb);
}

t_stack	simple_sort(t_stack aetb)
{
	int	size;

	if (ft_lstsize(aetb.stack_a) == 0
		|| ft_sorted(aetb.stack_a)
		|| ft_lstsize(aetb.stack_a) == 1)
		return (aetb);
	size = ft_lstsize(aetb.stack_a);
	if (size == 2)
		sa(&aetb.stack_a);
	else if (size == 3)
		aetb.stack_a = sort_three(aetb.stack_a);
	else if (size == 4)
		aetb = sort_four(aetb);
	else if (size == 5)
		aetb = sort_five(aetb);
	return (aetb);
}
