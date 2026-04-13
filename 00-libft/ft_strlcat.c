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

	x = 0;
	while (*dst && x < dstsize)
	{
		dst++;
		x++;
	}
	ft_strlcpy(dst, src, dstsize - x);
	return (x + ft_strlen(src));
}
