/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:43:30 by csubires          #+#    #+#             */
/*   Updated: 2024/07/04 12:19:11 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/push_swap.h"

void	ft_mov_ccc(t_stack **a, t_stack **b, char *str)
{
	if (str[2] == 'a')
		ft_rra(a, 0);
	else if (str[2] == 'b')
		ft_rrb(b, 0);
	else if (str[2] == 'r')
		ft_rrr(a, b, 0);
	else
		ft_print_error();
}

char	*ft_mov_cc(t_stack **a, t_stack **b, char *str)
{
	if (str[3] == '\n' && str[0] == 'r' && str[1] == 'r')
		ft_mov_ccc(a, b, str);
	else if (str[2] == '\n' && str[0] == 'r' && str[1] == 'a')
		ft_ra(a, 0);
	else if (str[2] == '\n' && str[0] == 'r' && str[1] == 'b')
		ft_rb(b, 0);
	else if (str[2] == '\n' && str[0] == 'r' && str[1] == 'r')
		ft_rr(a, b, 0);
	else if (str[2] == '\n' && str[0] == 's' && str[1] == 'a')
		ft_sa(a, 0);
	else if (str[2] == '\n' && str[0] == 's' && str[1] == 'b')
		ft_sb(b, 0);
	else if (str[2] == '\n' && str[0] == 's' && str[1] == 's')
		ft_ss(a, b, 0);
	else if (str[2] == '\n' && str[0] == 'p' && str[1] == 'a')
		ft_pa(a, b, 0);
	else if (str[2] == '\n' && str[0] == 'p' && str[1] == 'b')
		ft_pb(a, b, 0);
	else
		ft_print_error();
	return (ft_get_next_line(0));
}

void	ft_strcheck(t_stack **a, t_stack **b, char *str)
{
	char	*tmp;

	while (str && *str != '\n')
	{
		tmp = str;
		str = ft_mov_cc(a, b, str);
		free(tmp);
	}
	if (*b)
		write(1, "KO\n", 3);
	else if (!ft_issorted(*a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	ft_stk_free(b);
	ft_stk_free(a);
	free(str);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	*str;

	if (argc == 1)
		return (0);
	a = ft_parse(argc, argv);
	if (!a || ft_check_duplicate(a))
	{
		ft_stk_free(&a);
		ft_print_error();
	}
	b = 0;
	str = ft_get_next_line(0);
	if (!str && !ft_issorted(a))
		write(1, "KO\n", 3);
	else if (!str && ft_issorted(a))
		write(1, "OK\n", 3);
	else
		ft_strcheck(&a, &b, str);
	return (0);
}
