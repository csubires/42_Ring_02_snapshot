/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:48:34 by csubires          #+#    #+#             */
/*   Updated: 2024/04/22 16:12:13 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nwords(const char *str, char c)
{
	int	x;
	int	start;

	x = 0;
	start = 0;
	while (*str)
	{
		if (*str != c && start == 0)
		{
			start = 1;
			x++;
		}
		else if (*str == c)
			start = 0;
		str++;
	}
	return (x);
}

static char	*ft_cutword(char **arr, const char *s, int start, int end)
{
	char	*a_word;
	int		x;

	x = 0;
	a_word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!a_word)
	{
		x = 0;
		while (arr[x])
			free(arr[x++]);
		free(arr);
		return (0);
	}
	while (start < end)
		a_word[x++] = s[start++];
	a_word[x] = '\0';
	return (a_word);
}

static char	**ft_arrayptr(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (0);
	arr = (char **)malloc((ft_nwords(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (0);
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	x;
	size_t	y;
	int		start;
	char	**arr;

	arr = ft_arrayptr(s, c);
	if (!arr)
		return (0);
	x = 0;
	y = 0;
	start = -1;
	while (x <= ft_strlen(s))
	{
		if (s[x] != c && start < 0)
			start = x;
		else if ((s[x] == c || x == ft_strlen(s)) && start >= 0)
		{
			arr[y++] = ft_cutword(arr, s, start--, x);
			start = -1;
		}
		x++;
	}
	arr[y] = 0;
	return (arr);
}
