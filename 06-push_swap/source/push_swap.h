/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 22:30:08 by csubires          #+#    #+#             */
/*   Updated: 2024/07/05 07:37:19 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../stack/stack.h"

# ifndef MAX_INT
#  define MAX_INT 2147483647
# endif

# ifndef MIN_INT
#  define MIN_INT -2147483648
# endif

//	FT_PARSE.C
void	ft_free_split(char **arr);
int		ft_check_duplicate(t_stack *a);
t_stack	*ft_str_parse(char *str, int *error);
t_stack	*ft_parse(int argc, char *argv[]);

//	FT_ROTATE.C
int		ft_rotate_rarb(t_stack **a, t_stack **b, int nbr, char aorb);
int		ft_rotate_rrarrb(t_stack **a, t_stack **b, int nbr, char aorb);
int		ft_rotate_rarrb(t_stack **a, t_stack **b, int nbr, char aorb);
int		ft_rotate_rrarb(t_stack **a, t_stack **b, int nbr, char aorb);
int		ft_min_rotates(t_stack *a, t_stack *b, char aorb);

//	FT_CALCULATE.C
int		ft_numof_rarb(t_stack *s1, t_stack *s2, int nbr, char aorb);
int		ft_numof_rrarrb(t_stack *s1, t_stack *s2, int nbr, char aorb);
int		ft_numof_rarrb(t_stack *s1, t_stack *s2, int nbr, char aorb);
int		ft_numof_rrarb(t_stack *s1, t_stack *s2, int nbr, char aorb);

//	FT_SORT
void	ft_sort_b(t_stack **a, t_stack **b);
t_stack	**ft_sort_a(t_stack **a, t_stack **b);
t_stack	*ft_init_b(t_stack **a);
void	ft_sort(t_stack **a);

#endif
