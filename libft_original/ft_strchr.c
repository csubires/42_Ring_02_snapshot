/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:47:03 by csubires          #+#    #+#             */
/*   Updated: 2024/04/18 09:50:06 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	x;

	x = 0;
	while (s[x])
	{
		if (s[x] == (char)c)
			return ((char *)s + x);
		x++;
	}
	if (s[x] == (char)c)
		return ((char *)s + x);
	else
		return (0);
}
