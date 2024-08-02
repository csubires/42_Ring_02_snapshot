/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:43:30 by csubires          #+#    #+#             */
/*   Updated: 2024/07/04 09:57:01 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_search_nbr(t_stack *s, int nbr)
{
	size_t	x;

	x = 0;
	while (s->nbr != nbr && ++x)
		s = s->next;
	return (x);
}

int	ft_orderly_place(t_stack *s, int nbr, int aorb)
{
	size_t	x;
	t_stack	*tmp;

	x = 1;
	tmp = s->next;
	if (aorb == 'a')
	{
		while ((s->nbr > nbr || tmp->nbr < nbr) && ++x)
		{
			s = s->next;
			tmp = s->next;
		}
	}
	else
	{
		while ((s->nbr < nbr || tmp->nbr > nbr) && ++x)
		{
			s = s->next;
			tmp = s->next;
		}
	}
	return (x);
}

int	ft_best_place(t_stack *s, int nbr, int aorb)
{
	size_t	x;

	x = 1;
	if ((aorb == 'b' && nbr > s->nbr && nbr < ft_stk_last(s)->nbr) || \
		(aorb == 'a' && nbr < s->nbr && nbr > ft_stk_last(s)->nbr))
		x = 0;
	else if (nbr > ft_minmax(s, 1) || nbr < ft_minmax(s, 0))
	{
		if (aorb == 'a')
			x = ft_search_nbr(s, ft_minmax(s, 0));
		else
			x = ft_search_nbr(s, ft_minmax(s, 1));
	}
	else
		x = ft_orderly_place(s, nbr, aorb);
	return (x);
}

int	ft_minmax(t_stack *s, int minormax)
{
	int	x;

	x = s->nbr;
	while (s)
	{
		if (minormax && s->nbr > x)
			x = s->nbr;
		if (!minormax && s->nbr < x)
			x = s->nbr;
		s = s->next;
	}
	return (x);
}

int	ft_issorted(t_stack *s)
{
	int	x;

	x = s->nbr;
	while (s)
	{
		if (x > s->nbr)
			return (0);
		x = s->nbr;
		s = s->next;
	}
	return (1);
}
