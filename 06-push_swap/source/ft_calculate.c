/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:43:30 by csubires          #+#    #+#             */
/*   Updated: 2024/07/05 07:22:34 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_numof_rarb(t_stack *s1, t_stack *s2, int nbr, char aorb)
{
	int		rots_s1;
	int		rots_s2;
	t_stack	*tmp;

	if (aorb != 'a')
	{
		tmp = s2;
		s2 = s1;
		s1 = tmp;
	}
	rots_s1 = ft_best_place(s1, nbr, aorb);
	rots_s2 = ft_search_nbr(s2, nbr);
	return (ft_maximum(rots_s1, rots_s2));
}

int	ft_numof_rrarrb(t_stack *s1, t_stack *s2, int nbr, char aorb)
{
	t_stack	*tmp;
	int		x;
	int		rots_s1;
	int		rots_s2;

	x = 0;
	if (aorb != 'a')
	{
		tmp = s2;
		s2 = s1;
		s1 = tmp;
	}
	rots_s1 = ft_best_place(s1, nbr, aorb);
	rots_s2 = ft_search_nbr(s2, nbr);
	if (rots_s1)
		x = ft_stk_size(s1) - rots_s1;
	if (rots_s2 && (x < (ft_stk_size(s2) - rots_s2)))
		x = ft_stk_size(s2) - rots_s2;
	return (x);
}

int	ft_numof_rarrb(t_stack *s1, t_stack *s2, int nbr, char aorb)
{
	int	x;
	int	place;

	x = 0;
	if (aorb == 'a')
	{
		place = ft_search_nbr(s2, nbr);
		if (place)
			x = ft_stk_size(s2) - place;
		x = ft_best_place(s1, nbr, 'a') + x;
	}
	else
	{
		place = ft_best_place(s2, nbr, 'b');
		if (place)
			x = ft_stk_size(s2) - place;
		x = ft_search_nbr(s1, nbr) + x;
	}
	return (x);
}

int	ft_numof_rrarb(t_stack *s1, t_stack *s2, int nbr, char aorb)
{
	int	x;
	int	place;

	x = 0;
	if (aorb == 'a')
	{
		place = ft_best_place(s1, nbr, 'a');
		if (place)
			x = ft_stk_size(s1) - place;
		x = ft_search_nbr(s2, nbr) + x;
	}
	else
	{
		place = ft_search_nbr(s1, nbr);
		if (place)
			x = ft_stk_size(s1) - place;
		x = ft_best_place(s2, nbr, 'b') + x;
	}
	return (x);
}
