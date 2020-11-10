/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:25:36 by eugeniagl         #+#    #+#             */
/*   Updated: 2020/11/10 18:17:26 by phassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	char_c;
	char	*char_s;
	size_t	s_len;

	char_c = (char)c;
	char_s = (char *)s;
	s_len = ft_strlen(s);
	if (c == '\0')
		return (char_s + s_len);
	while (s_len--)
	{
		if (char_s[s_len] == char_c)
			return (char_s + s_len);
	}
	if (char_s[s_len] == char_c)
		return (char_s + s_len);
	return (0);
}
