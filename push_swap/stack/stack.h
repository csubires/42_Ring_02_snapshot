/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 22:30:08 by csubires          #+#    #+#             */
/*   Updated: 2024/07/04 09:52:40 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//	MOVEMENTS_01.C
void		ft_sa(t_stack **a, int show);
void		ft_sb(t_stack **b, int show);
void		ft_ss(t_stack **a, t_stack **b, int show);
void		ft_pa(t_stack **a, t_stack **b, int show);
void		ft_pb(t_stack **a, t_stack **b, int show);

//	MOVEMENTS_02.C
void		ft_ra(t_stack **a, int show);
void		ft_rb(t_stack **b, int show);
void		ft_rr(t_stack **a, t_stack **b, int show);
void		ft_rra(t_stack **a, int show);
void		ft_rrb(t_stack **b, int show);

//	MOVEMENTS_03.C
void		ft_rrr(t_stack **a, t_stack **b, int show);
void		ft_show_ornot(char *mov, int show);
void		ft_print_error(void);
void		ft_threenodes(t_stack **s);

//	STACK.C
void		ft_stk_free(t_stack **s);
t_stack		*ft_new_node(int nbr);
t_stack		*ft_stk_last(t_stack *s);
void		ft_stk_add(t_stack **s, t_stack *new);
int			ft_stk_size(t_stack *s);

//	UTILS.C
int			ft_search_nbr(t_stack *s, int nbr);
int			ft_orderly_place(t_stack *s, int nbr, int aorb);
int			ft_best_place(t_stack *s, int nbr, int aorb);
int			ft_minmax(t_stack *s, int minormax);
int			ft_issorted(t_stack *s);

#endif
