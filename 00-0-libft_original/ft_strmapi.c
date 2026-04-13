/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:49:12 by csubires          #+#    #+#             */
/*   Updated: 2024/04/23 15:05:14 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str_mapi;
	unsigned int	len_s;

	len_s = ft_strlen(s);
	str_mapi = (char *)malloc(sizeof(char) * (len_s + 1));
	if (!str_mapi)
		return (0);
	str_mapi[len_s] = '\0';
	while (len_s)
	{
		len_s--;
		str_mapi[len_s] = f(len_s, s[len_s]);
	}
	return (str_mapi);
}
