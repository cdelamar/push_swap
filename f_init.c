/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:34:47 by cdelamar          #+#    #+#             */
/*   Updated: 2024/03/27 03:00:51 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	index_0(t_list *stack)
{
	while (stack)
	{
		stack->index = 0;
		stack = stack->next;
	}
}

void	set_index(t_list **stack)
{
	static int	i = 1;
	int			min;
	t_list		*head;

	min = INT_MAX;
	head = *stack;
	while (head)
	{
		if (head->content < min && head->index == 0)
			min = head->content;
		head = head->next;
	}
	head = *stack;
	while (head->content != min)
		head = head->next;
	head->index = i;
	i++;
}

void	while_set(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head)
	{
		set_index(stack);
		head = head->next;
	}
	stack = &head;
}

void	ft_init_stack(t_list **stack, int argc, char **argv)
{
	int		i;
	char	**args;
	t_list	*new;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	index_0(*stack);
	while_set(stack);
	if (argc == 2)
		ft_free_tab(args);
}
