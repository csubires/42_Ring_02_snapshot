/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:43:30 by csubires          #+#    #+#             */
/*   Updated: 2024/07/05 07:37:07 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_b(t_stack **a, t_stack **b)
{
	int		x;
	t_stack	*tmp;

	while (ft_stk_size(*a) > 3 && !ft_issorted(*a))
	{
		tmp = *a;
		x = ft_min_rotates(*a, *b, 'a');
		while (x >= 0)
		{
			if (x == ft_numof_rarb(*a, *b, tmp->nbr, 'b'))
				x = ft_rotate_rarb(a, b, tmp->nbr, 'a');
			else if (x == ft_numof_rrarrb(*a, *b, tmp->nbr, 'b'))
				x = ft_rotate_rrarrb(a, b, tmp->nbr, 'a');
			else if (x == ft_numof_rarrb(*a, *b, tmp->nbr, 'b'))
				x = ft_rotate_rarrb(a, b, tmp->nbr, 'a');
			else if (x == ft_numof_rrarb(*a, *b, tmp->nbr, 'b'))
				x = ft_rotate_rrarb(a, b, tmp->nbr, 'a');
			else
				tmp = tmp->next;
		}
	}
}

t_stack	**ft_sort_a(t_stack **a, t_stack **b)
{
	int		x;
	t_stack	*tmp;

	while (*b)
	{
		tmp = *b;
		x = ft_min_rotates(*a, *b, 'b');
		while (x >= 0)
		{
			if (x == ft_numof_rarb(*a, *b, tmp->nbr, 'a'))
				x = ft_rotate_rarb(a, b, tmp->nbr, 'b');
			else if (x == ft_numof_rarrb(*a, *b, tmp->nbr, 'a'))
				x = ft_rotate_rarrb(a, b, tmp->nbr, 'b');
			else if (x == ft_numof_rrarrb(*a, *b, tmp->nbr, 'a'))
				x = ft_rotate_rrarrb(a, b, tmp->nbr, 'b');
			else if (x == ft_numof_rrarb(*a, *b, tmp->nbr, 'a'))
				x = ft_rotate_rrarb(a, b, tmp->nbr, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (a);
}

t_stack	*ft_init_b(t_stack **a)
{
	t_stack	*b;

	b = 0;
	if (ft_stk_size(*a) > 3 && !ft_issorted(*a))
		ft_pb(a, &b, 1);
	if (ft_stk_size(*a) > 3 && !ft_issorted(*a))
		ft_pb(a, &b, 1);
	if (ft_stk_size(*a) > 3 && !ft_issorted(*a))
		ft_sort_b(a, &b);
	if (!ft_issorted(*a))
		ft_threenodes(a);
	return (b);
}

void	ft_sort(t_stack **a)
{
	t_stack	*b;
	int		x;

	b = 0;
	if (ft_stk_size(*a) == 2)
		ft_sa(a, 1);
	else
	{
		b = ft_init_b(a);
		a = ft_sort_a(a, &b);
		x = ft_search_nbr(*a, ft_minmax(*a, 0));
		if (x < ft_stk_size(*a) - x)
			x = 1;
		else
			x = 0;
		while ((*a)->nbr != ft_minmax(*a, 0))
		{
			if (x)
				ft_ra(a, 1);
			else
				ft_rra(a, 1);
		}
	}
}
