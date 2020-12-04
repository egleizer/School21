/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:01:27 by eugeniagl         #+#    #+#             */
/*   Updated: 2020/11/18 11:03:26 by eugeniagl        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

char	*ft_strjoin(char *s1, char *s2, int buf_len);
int		get_next_line(int fd, char **line);
size_t	ft_strlen(char *s);
void	*ft_memmove(void *dst, void *src, size_t len);
int		no_return(char *line);
int		has_eof(char *line);
char	*retrieve_line(char *whole_line);
char	*retrieve_remains(char *whole_line);

#endif
