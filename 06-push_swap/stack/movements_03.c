/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_03.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:43:30 by csubires          #+#    #+#             */
/*   Updated: 2024/07/04 07:29:14 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_rrr(t_stack **a, t_stack **b, int show)
{
	if ((ft_stk_size(*a) > 1) && (ft_stk_size(*b) > 1))
	{
		ft_rra(a, 0);
		ft_rrb(b, 0);
		ft_show_ornot("rrr\n", show);
	}
}

void	ft_show_ornot(char *mov, int show)
{
	size_t	x;

	if (show)
	{
		x = 0;
		while (mov[x])
			x++;
		write(1, mov, x);
	}
}

void	ft_print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_threenodes(t_stack **s)
{
	int	x;

	x = ft_minmax(*s, 1);
	if ((*s)->nbr == x)
		ft_ra(s, 1);
	else if ((*s)->next->nbr == x)
		ft_rra(s, 1);
	if ((*s)->nbr > (*s)->next->nbr)
		ft_sa(s, 1);
}
