/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:10:11 by cdelamar          #+#    #+#             */
/*   Updated: 2024/03/27 03:02:04 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_lstprint(t_list *stack)
{
	while (stack)
	{
		printf("content : %d	index : %d\n", stack->content, stack->index);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_sort	sort;
	t_stack	ab;

	if (argc < 2 || argv[1] == NULL || argv[1][0] == '\0')
		ft_error(ARGC_FAILURE);
	ft_args_check(argc, argv);
	stack_a = NULL;
	stack_b = NULL;
	ft_init_stack(&stack_a, argc, argv);
	if (ft_sorted(stack_a))
		ft_free_list(&stack_a);
	else if (ft_lstsize(stack_a) <= 5)
	{
		ab.stack_a = stack_a;
		ab.stack_b = stack_b;
		ab = simple_sort(ab);
		ft_free_all(ab.stack_a, ab.stack_b, &sort);
	}
	else
		radix(stack_a, stack_b, &sort);
	return (EXIT_SUCCESS);
}
