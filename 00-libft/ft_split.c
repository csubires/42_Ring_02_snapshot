/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:48:34 by csubires          #+#    #+#             */
/*   Updated: 2024/07/08 16:34:14 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(unsigned int len, char **arr_ptr)
{
	while (len-- > 0)
	{
		free(arr_ptr[len]);
		arr_ptr[len] = 0;
	}
	free(arr_ptr);
	arr_ptr = 0;
}

static int	ft_num_words(const char *s, char c)
{
	unsigned int	num;
	unsigned int	x;

	x = 0;
	num = 0;
	while (s[x])
	{
		if (s[x] != c)
		{
			num++;
			while (s[x] && s[x] != c)
				x++;
		}
		else if (s[x] == c)
			x++;
	}
	return (num);
}

static unsigned int	get_word_len(char const *s, char c)
{
	unsigned int	x;

	x = 0;
	while (s[x] && s[x] != c)
		x++;
	return (x);
}

static char	**ft_cut_words(char const *s, char c, char **arr_ptr, int num_words)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < num_words)
	{
		while (s[y] && s[y] == c)
			y++;
		arr_ptr[x] = ft_substr(s, y, get_word_len(&s[y], c));
		if (!arr_ptr[x])
		{
			ft_free(x, arr_ptr);
			return (0);
		}
		while (s[y] && s[y] != c)
			y++;
		x++;
	}
	arr_ptr[x] = 0;
	return (arr_ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr_ptr;
	int		num_words;

	if (!s)
		return (0);
	num_words = ft_num_words(s, c);
	arr_ptr = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!arr_ptr)
		return (0);
	arr_ptr = ft_cut_words(s, c, arr_ptr, num_words);
	return (arr_ptr);
}
