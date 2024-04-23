/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:30:38 by cdelamar          #+#    #+#             */
/*   Updated: 2024/03/27 03:04:05 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# define INT_MIN			-2147483648   
# define INT_MAX			2147483647

# define NUM_FAILURE			"invalid argument\n"
# define ARGC_FAILURE    		"incorrect argument\n"
# define DOUBLON_FAILURE		"argument invalid\n"
# define INT_SIZE_FAILURE		"arguments value invalid, int limit outpassed\n"
# define SWAP_FAILURE			"swapping failure"

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_sort
{
	int				lst_size;
	int				bits_max;
	int				i;
	int				j;
	struct s_sort	*next;
}	t_sort;

typedef struct s_stack
{
	t_list	*stack_a;
	t_list	*stack_b;
}	t_stack;

// list (a maitriser)
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);

//t_list	*ft_lstnew(int content);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);

//push
int		push(t_list **src, t_list **dest);
int		pb(t_list **a, t_list**b);
int		pa(t_list **a, t_list **b);

//swap
int		swap(t_list **stack);
int		sa(t_list **a);
int		sb(t_list **b);
int		ss(t_list **a, t_list **b);

//rotate
int		rotate(t_list **stack);
int		ra(t_list **a);
int		rb(t_list **b);
int		rr(t_list **a, t_list **b);

//reverse_rotate
int		reverse_rotate(t_list **stack);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);

//arg check
void	ft_args_check(int argc, char **argv);
void	ft_free_tab(char **tab);
void	ft_free_list(t_list **stack);
void	ft_free_sort(t_sort *sort);
void	ft_free_all(t_list *stack_a, t_list *stack_b, t_sort *sort);
int		ft_error(char *s);

//initialize
void	ft_index_stack(t_list **stack);
void	ft_init_stack(t_list **stack, int argc, char **argv);

// libft	printf("begin avant loop : %d")
char	**ft_split(char *s, char c);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_atoi(char *nptr);
int		ft_isdigit(int c);

// test
void	ft_check_args(int argc, char **argv);
void	ft_lstprint(t_list *stack_a);

//ft_error
void	ft_putendl_fd(char *str, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putchar_fd(char c, int fd);

//test
void	ft_binary(int index);
int		index_max(t_list *stack);
void	radix(t_list *stack_a, t_list *stack_b, t_sort *sort);
bool	ft_sorted(t_list *stack);

//simple_sort
t_stack	simple_sort(t_stack aetb);

//simple_sort_ft

int		ft_min(t_list *stack, int nb);
int		ft_range(t_list *stack, int index);
t_list	*ra_sa_ssa(t_list *stack);
t_list	*sa_rra(t_list *stack);

#endif