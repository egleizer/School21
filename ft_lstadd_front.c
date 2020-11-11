/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:19:30 by eugeniagl         #+#    #+#             */
/*   Updated: 2020/11/10 18:22:32 by phassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*elem;

	if (lst && *lst)
	{
		elem = *lst;
		new->next = elem;
		*lst = new;
	}
	else if (lst)
		*lst = new;
}
