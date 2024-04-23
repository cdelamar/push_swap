/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:22:11 by cdelamar          #+#    #+#             */
/*   Updated: 2024/03/25 13:22:42 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	words_counter(char const *s, char c)
{
	int	counter;

	counter = 0;
	if (!*s)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			counter++;
		while (*s != c && *s)
			s++;
	}
	return (counter);
}

static size_t	get_word_size(char const *s, char c)
{
	size_t	word_size;

	word_size = 0;
	while (*s == c && *s)
		s++;
	while (*s != c && *s)
	{
		word_size++;
		s++;
	}
	return (word_size);
}

char	**ft_split(char *s, char c)
{
	char	**res;
	int		i;
	int		words;
	size_t	word_size;

	i = 0;
	words = words_counter(s, c);
	res = (char **)malloc((words + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			word_size = get_word_size(s, c);
			res[i++] = ft_substr(s, 0, word_size);
			s += word_size;
		}
	}
	res[i] = NULL;
	return (res);
}
