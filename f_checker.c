/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_checker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:29:44 by cdelamar          #+#    #+#             */
/*   Updated: 2024/03/25 11:31:58 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static	bool	appear_twice(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (true);
		i++;
	}
	return (false);
}

static	bool	is_number(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '-' && (s[1] >= '0' && s[1] <= '9'))
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (false);
		i++;
	}
	return (true);
}

static long	ft_atol(char *nptr)
{
	long	sign;
	long	num;

	sign = 1;
	num = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = num * 10 + (*nptr - '0');
		nptr++;
	}
	return (num * sign);
}

void	ft_args_check(int argc, char **argv)
{
	long	buf;
	char	**args;
	int		i;

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
		buf = ft_atol(args[i]);
		if (is_number(args[i]) == false)
			ft_error(NUM_FAILURE);
		if (appear_twice(buf, args, i) == true)
			ft_error(DOUBLON_FAILURE);
		if (buf < -2147483648 || buf > INT_MAX)
			ft_error(INT_SIZE_FAILURE);
		i++;
	}
	if (argc == 2)
		ft_free_tab(args);
}
