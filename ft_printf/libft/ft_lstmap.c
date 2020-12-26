/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phassan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:39:38 by phassan           #+#    #+#             */
/*   Updated: 2020/11/10 16:39:41 by phassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**new_list;
	t_list	*next_elem;

	new_list = 0;
	*new_list = 0;
	while (lst)
	{
		next_elem = ft_lstnew(f(lst->content));
		if (!next_elem)
		{
			ft_lstclear(new_list, del);
			return (0);
		}
		ft_lstadd_back(new_list, next_elem);
		lst = lst->next;
	}
	return (*new_list);
}
