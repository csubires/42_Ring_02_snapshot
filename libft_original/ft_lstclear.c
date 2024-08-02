/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:48:34 by csubires          #+#    #+#             */
/*   Updated: 2024/04/18 13:30:16 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp_ptr;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp_ptr = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp_ptr;
	}
	*lst = 0;
}
