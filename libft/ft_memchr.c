/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:59:24 by csubires          #+#    #+#             */
/*   Updated: 2024/04/22 10:03:58 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			x;
	unsigned char	*tmp_s;

	tmp_s = (unsigned char *)s;
	x = 0;
	while (x < n)
	{
		if ((unsigned char)*tmp_s == (unsigned char)c)
			return (tmp_s);
		tmp_s++;
		x++;
	}
	return (0);
}
