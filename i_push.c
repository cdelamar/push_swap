/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:29:21 by cdelamar          #+#    #+#             */
/*   Updated: 2024/03/25 13:29:23 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	push(t_list **src, t_list **dest)
{
	t_list	*buf;
	t_list	*head_src;
	t_list	*head_dest;

	if (ft_lstsize (*src) == 0)
		return (-1);
	head_dest = *dest;
	head_src = *src;
	buf = head_src;
	head_src = head_src->next;
	*src = head_src;
	if (!head_dest)
	{
		head_dest = buf;
		head_dest->next = NULL;
		*dest = head_dest;
	}
	else
	{
		buf->next = head_dest;
		*dest = buf;
	}
	return (0);
}

int	pb(t_list **a, t_list **b)
{
	if (push(a, b) == -1)
		return (-1);
	write (1, "pb\n", 3);
	return (0);
}

int	pa(t_list **b, t_list **a)
{
	if (push(a, b) == -1)
		return (-1);
	write(1, "pa\n", 3);
	return (0);
}
