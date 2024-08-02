/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:43:30 by csubires          #+#    #+#             */
/*   Updated: 2024/07/04 10:44:11 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;

	if (argc == 1)
		return (0);
	a = ft_parse(argc, argv);
	if (!a || ft_check_duplicate(a))
	{
		ft_stk_free(&a);
		ft_print_error();
	}
	if (!ft_issorted(a))
		ft_sort(&a);
	ft_stk_free(&a);
	return (0);
}
