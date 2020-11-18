/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:00:11 by eugeniagl         #+#    #+#             */
/*   Updated: 2020/11/10 12:00:14 by eugeniagl        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*pointer;

	if (!(pointer = (t_list *)malloc(sizeof(t_list *))))
		return (0);
	if (!content)
		pointer->content = 0;
	else
	{
		if (!(pointer->content = malloc(sizeof(content))))
			return (0);
		ft_memcpy(pointer->content, content, ft_strlen(content));
	}
	pointer->next = 0;
	return (pointer);
}
