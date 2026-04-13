/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:43:30 by csubires          #+#    #+#             */
/*   Updated: 2024/07/04 07:29:14 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_stk_free(t_stack **s)
{
	t_stack	*tmp;

	if (s)
	{
		while (*s)
		{
			tmp = (*s)->next;
			(*s)->nbr = 0;
			free(*s);
			*s = tmp;
		}
	}
	s = 0;
}

t_stack	*ft_new_node(int nbr)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof (t_stack));
	if (!new)
		ft_print_error();
	new->nbr = nbr;
	new->next = 0;
	return (new);
}

t_stack	*ft_stk_last(t_stack *s)
{
	if (ft_stk_size(s))
	{
		while (s->next)
			s = s->next;
		return (s);
	}
	return (0);
}

void	ft_stk_add(t_stack **s, t_stack *new)
{
	if (s)
	{
		if (ft_stk_size(*s))
			(ft_stk_last(*s))->next = new;
		else
			*s = new;
	}
}

int	ft_stk_size(t_stack *s)
{
	size_t	x;

	x = 0;
	while (s && ++x)
		s = s->next;
	return (x);
}
