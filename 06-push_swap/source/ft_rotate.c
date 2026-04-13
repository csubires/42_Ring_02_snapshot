/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:43:30 by csubires          #+#    #+#             */
/*   Updated: 2024/07/05 07:33:50 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate_rarb(t_stack **a, t_stack **b, int nbr, char aorb)
{
	if (aorb == 'a')
	{
		while ((*a)->nbr != nbr && ft_best_place(*b, nbr, 'b') > 0)
			ft_rr(a, b, 1);
		while ((*a)->nbr != nbr)
			ft_ra(a, 1);
		while (ft_best_place(*b, nbr, 'b') > 0)
			ft_rb(b, 1);
		ft_pb(a, b, 1);
	}
	else
	{
		while ((*b)->nbr != nbr && ft_best_place(*a, nbr, 'a') > 0)
			ft_rr(a, b, 1);
		while ((*b)->nbr != nbr)
			ft_rb(b, 1);
		while (ft_best_place(*a, nbr, 'a') > 0)
			ft_ra(a, 1);
		ft_pa(a, b, 1);
	}
	return (-1);
}

int	ft_rotate_rrarrb(t_stack **a, t_stack **b, int nbr, char aorb)
{
	if (aorb == 'a')
	{
		while ((*a)->nbr != nbr && ft_best_place(*b, nbr, 'b') > 0)
			ft_rrr(a, b, 1);
		while ((*a)->nbr != nbr)
			ft_rra(a, 1);
		while (ft_best_place(*b, nbr, 'b') > 0)
			ft_rrb(b, 1);
		ft_pb(a, b, 1);
	}
	else
	{
		while ((*b)->nbr != nbr && ft_best_place(*a, nbr, 'a') > 0)
			ft_rrr(a, b, 1);
		while ((*b)->nbr != nbr)
			ft_rrb(b, 1);
		while (ft_best_place(*a, nbr, 'a') > 0)
			ft_rra(a, 1);
		ft_pa(a, b, 1);
	}
	return (-1);
}

int	ft_rotate_rarrb(t_stack **a, t_stack **b, int nbr, char aorb)
{
	if (aorb == 'a')
	{
		while ((*a)->nbr != nbr)
			ft_ra(a, 1);
		while (ft_best_place(*b, nbr, 'b') > 0)
			ft_rrb(b, 1);
		ft_pb(a, b, 1);
	}
	else
	{
		while (ft_best_place(*a, nbr, 'a') > 0)
			ft_ra(a, 1);
		while ((*b)->nbr != nbr)
			ft_rrb(b, 1);
		ft_pa(a, b, 1);
	}
	return (-1);
}

int	ft_rotate_rrarb(t_stack **a, t_stack **b, int nbr, char aorb)
{
	if (aorb == 'a')
	{
		while ((*a)->nbr != nbr)
			ft_rra(a, 1);
		while (ft_best_place(*b, nbr, 'b') > 0)
			ft_rb(b, 1);
		ft_pb(a, b, 1);
	}
	else
	{
		while (ft_best_place(*a, nbr, 'a') > 0)
			ft_rra(a, 1);
		while ((*b)->nbr != nbr)
			ft_rb(b, 1);
		ft_pa(a, b, 1);
	}
	return (-1);
}

int	ft_min_rotates(t_stack *a, t_stack *b, char aorb)
{
	t_stack	*tmp;
	int		x;

	if (aorb == 'a')
	{
		aorb = 'b';
		tmp = a;
	}
	else
	{
		aorb = 'a';
		tmp = b;
	}
	x = ft_numof_rarb(a, b, tmp->nbr, aorb);
	while (tmp)
	{
		x = ft_minimum(ft_numof_rarb(a, b, tmp->nbr, aorb), x);
		x = ft_minimum(ft_numof_rrarrb(a, b, tmp->nbr, aorb), x);
		x = ft_minimum(ft_numof_rarrb(a, b, tmp->nbr, aorb), x);
		x = ft_minimum(ft_numof_rrarb(a, b, tmp->nbr, aorb), x);
		tmp = tmp->next;
	}
	return (x);
}
