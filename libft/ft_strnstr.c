/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:30:11 by csubires          #+#    #+#             */
/*   Updated: 2024/04/23 15:35:44 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;
	size_t	y;

	if (!*needle)
		return ((char *)haystack);
	x = 0;
	y = 0;
	while (haystack[x] && x < len)
	{
		if (haystack[x] == needle[0])
		{
			while (needle[y] && haystack[x + y] == needle[y] && (x + y) < len)
			{
				if (needle[y + 1] == '\0')
					return ((char *) &haystack[x]);
				y++;
			}
		}
		x++;
	}
	return (0);
}
