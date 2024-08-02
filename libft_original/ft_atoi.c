/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:15:08 by csubires          #+#    #+#             */
/*   Updated: 2024/07/02 10:22:06 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || \
		c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned int	x;
	long long int	result;
	int	sign;

	sign = 1;
	result = 0;
	x = 0;
	while (str[x] && is_space(str[x]))
		x++;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			sign = -1;
		x++;
	}
	while (str[x] && ft_isdigit(str[x]))
	{
		result = (result * 10) + (str[x] - '0');
		x++;
	}
	return (result * sign);
}
