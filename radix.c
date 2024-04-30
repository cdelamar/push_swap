/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:43:08 by cdelamar          #+#    #+#             */
/*   Updated: 2024/03/27 04:00:05 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

bool	ft_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	set_bits_max(t_list *stack)
{
	int	bits_max;
	int	max;

	bits_max = 0;
	max = stack->index;
	while (stack)
	{
		if (max < stack->index)
			max = stack->index;
		stack = stack->next;
	}
	while (max)
	{
		max /= 2;
		bits_max++;
	}
	return (bits_max);
}

int	index_max(t_list *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->next && max < stack->next->index)
			max = stack->next->index;
		stack = stack->next;
	}
	return (max);
}

void	radix(t_list *stack_a, t_list *stack_b, t_sort *sort)
{
	t_list	*head_a;

	head_a = stack_a;
	sort->i = 0;
	sort->lst_size = ft_lstsize(stack_a);
	sort->bits_max = set_bits_max(stack_a);
	sort->next = NULL;
	while (sort->i < sort->bits_max)
	{
		sort->j = 0;
		while (sort->j < sort->lst_size)
		{
			head_a = stack_a;
			if (((head_a->index >> sort->i) & 1) == 1)
				ra(&stack_a);
			else
				pb(&stack_a, &stack_b);
			sort->j++;
		}
		while (ft_lstsize(stack_b) != 0)
			pa(&stack_a, &stack_b);
		sort->i++;
	}
	ft_free_all(stack_a, stack_b, sort);
}

	/*printf("\nliste A \n\n");
	ft_lstprint(stack_a);
	printf("\nliste B \n\n");
	ft_lstprint(stack_b);
	sft_free_sort(&sort);
	ft_free_list(&stack_a); // ft_free_tout
	ft_free_list(&stack_b);*/