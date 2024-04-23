/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:07:33 by cdelamar          #+#    #+#             */
/*   Updated: 2024/03/25 14:08:17 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	rotate(t_list **stack)
{
	t_list	*start;
	t_list	*end;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	start = *stack;
	end = ft_lstlast(start);
	*stack = start->next;
	start->next = NULL;
	end->next = start;
	return (0);
}

int	ra(t_list **a)
{
	if (rotate(a) == -1)
		return (-1);
	write(1, "ra\n", 3);
	return (0);
}

int	rb(t_list **b)
{
	if (rotate(b) == -1)
		return (-1);
	write(1, "rb\n", 3);
	return (0);
}

int	rr(t_list **a, t_list **b)
{
	if ((ft_lstsize(*a) < 2) || (ft_lstsize(*b) < 2))
		return (-1);
	write (1, "rr\n", 3);
	return (0);
}
