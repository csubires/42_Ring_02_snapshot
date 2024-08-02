/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:57:45 by csubires          #+#    #+#             */
/*   Updated: 2024/04/23 15:03:10 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (dst[x] && x < dstsize)
		x++;
	y = 0;
	while (src[y] && (y + x + 1) < dstsize)
	{
		dst[x + y] = src[y];
		y++;
	}
	if (x != dstsize)
		dst[x + y] = '\0';
	return (x + ft_strlen(src));
}
