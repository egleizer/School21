# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/06 15:29:33 by eugeniagl         #+#    #+#              #
#    Updated: 2020/11/06 15:29:36 by eugeniagl        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    =   ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_memccpy.c \
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c

BONUS   =   ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
                    ft_lstdelone.c ft_lstclear.c ft_lstiter.c


OBJS			= $(SRCS:.c=.o)
OBJSB			= $(BONUS:.c=.o)
CC     			= gcc
CFLAGS 			= -Wall -Wextra -Werror -I $(INC)
RM     			= rm -f
INC			    = libft.h

NAME    		= libft.a

all:        	  $(NAME)

$(NAME):		  $(OBJS) ${OBJSB}
				  ar rcs $(NAME) $(OBJS) ${OBJSB}

clean:
				  $(RM) $(OBJS) ${OBJSB}

fclean:    		  clean
		          $(RM) $(NAME)

re:        		  fclean $(NAME)

.PHONY:    		  all clean fclean re
