/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:45:46 by csubires          #+#    #+#             */
/*   Updated: 2024/06/04 19:25:31 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int		len_nbr;
	char	*res;

	res = ft_itoa(n);
	if (!res)
		return (-1);
	len_nbr = ft_putstr_fd(res, fd);
	free (res);
	return (len_nbr);
}
