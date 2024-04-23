/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:32:39 by cdelamar          #+#    #+#             */
/*   Updated: 2024/03/27 03:01:33 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_list(t_list **stack)
{
	t_list	*head;
	t_list	*buffer;

	head = *stack;
	while (head)
	{
		buffer = head;
		head = head->next;
		free(buffer);
		buffer = NULL;
	}
	stack = NULL;
}

void	ft_free_sort(t_sort *sort)
{
	t_sort	*head;
	t_sort	*buffer;

	head = sort;
	while (head)
	{
		buffer = head;
		head = head->next;
		free(buffer);
		buffer = NULL;
	}
	sort = NULL;
}

void	ft_free_all(t_list *stack_a, t_list *stack_b, t_sort *sort)
{
	(void)sort;
	ft_free_list(&stack_a);
	ft_free_list(&stack_b);
}
