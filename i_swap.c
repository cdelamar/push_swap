/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:11:59 by cdelamar          #+#    #+#             */
/*   Updated: 2024/03/25 15:09:13 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	int_swap(int *a, int *b)
{
	int		buffer;

	buffer = *b;
	*b = *a;
	*a = buffer;
}

int	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	first = *stack;
	second = first->next;
	int_swap(&first->content, &second->content);
	int_swap(&first->index, &second->index);
	return (0);
}

int	sa(t_list **a)
{
	if (swap(a) == -1)
		return (-1);
	write(1, "sa\n", 3);
	return (0);
}

int	sb(t_list **b)
{
	if (swap(b) == -1)
		return (-1);
	write(1, "sb\n", 3);
	return (0);
}

int	ss(t_list **a, t_list **b)
{
	if (swap(a) == -1 || swap(b) == -1)
		return (-1);
	write(1, "ss\n", 3);
	return (0);
}
