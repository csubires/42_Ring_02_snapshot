/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:47:03 by csubires          #+#    #+#             */
/*   Updated: 2024/04/22 09:53:34 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	len;
	const char		*tmp_s;

	tmp_s = s;
	len = ft_strlen(tmp_s);
	tmp_s += len;
	while (tmp_s >= s)
		if (*tmp_s-- == (char)c)
			return ((char *)tmp_s + 1);
	return (0);
}
