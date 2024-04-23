/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_reverserotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:43:23 by cdelamar          #+#    #+#             */
/*   Updated: 2024/03/25 13:43:24 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	reverse_rotate(t_list **stack)
{
	t_list	*start;
	t_list	*end;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	start = *stack;
	end = ft_lstlast(start);
	while (start->next->next)
		start = start->next;
	start->next = NULL;
	end->next = *stack;
	*stack = end;
	return (0);
}

int	rra(t_list **stack_a)
{
	if (reverse_rotate(stack_a) == -1)
		return (-1);
	write(1, "rra\n", 4);
	return (0);
}

int	rrb(t_list **stack_b)
{
	if (reverse_rotate(stack_b) == -1)
		return (-1);
	write(1, "rrb\n", 4);
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if (reverse_rotate(stack_a) || reverse_rotate(stack_b) == -1)
		return (-1);
	write(1, "rrr\n", 4);
	return (0);
}
