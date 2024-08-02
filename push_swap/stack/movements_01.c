/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:43:30 by csubires          #+#    #+#             */
/*   Updated: 2024/07/04 07:29:14 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_sa(t_stack **a, int show)
{
	t_stack	*tmp;

	if (ft_stk_size(*a) > 1)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = (*a)->next;
		(*a)->next = tmp;
		ft_show_ornot("sa\n", show);
	}
}

void	ft_sb(t_stack **b, int show)
{
	t_stack	*tmp;

	if (ft_stk_size(*b) > 1)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = (*b)->next;
		(*b)->next = tmp;
		ft_show_ornot("sb\n", show);
	}
}

void	ft_ss(t_stack **a, t_stack **b, int show)
{
	if ((ft_stk_size(*a) > 1) && (ft_stk_size(*b) > 1))
	{
		ft_sa(a, 0);
		ft_sb(b, 0);
		ft_show_ornot("ss\n", show);
	}
}

void	ft_pa(t_stack **a, t_stack **b, int show)
{
	t_stack	*tmp;

	if (ft_stk_size(*b))
	{
		tmp = *a;
		*a = *b;
		*b = (*b)->next;
		(*a)->next = tmp;
		ft_show_ornot("pa\n", show);
	}
}

void	ft_pb(t_stack **a, t_stack **b, int show)
{
	t_stack	*tmp;

	if (ft_stk_size(*a))
	{
		tmp = *b;
		*b = *a;
		*a = (*a)->next;
		(*b)->next = tmp;
		ft_show_ornot("pb\n", show);
	}
}
