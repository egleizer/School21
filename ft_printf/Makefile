# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/07 15:26:39 by eugeniagl         #+#    #+#              #
#    Updated: 2020/12/07 15:26:45 by eugeniagl        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS            =   ft_one_parse.c ft_printf.c one_var_print.c print_character.c \
                        print_extra.c print_hex.c print_int.c print_string.c \
                         print_unsigned_hex.c print_unsigned_int.c print_void.c \
                         print_int_extra.c

LIBFT           =   libft/ft_isalnum.c libft/ft_isprint.c libft/ft_memcmp.c  libft/ft_putchar_fd.c libft/ft_split.c \
                    libft/ft_strlcat.c libft/ft_strncmp.c libft/ft_substr.c libft/ft_atoi.c libft/ft_isalpha.c \
                    libft/ft_itoa.c libft/ft_memcpy.c  libft/ft_putendl_fd.c libft/ft_strchr.c  libft/ft_strlcpy.c \
                    libft/ft_strnstr.c libft/ft_tolower.c libft/ft_bzero.c   libft/ft_isascii.c libft/ft_memccpy.c \
                    libft/ft_memmove.c libft/ft_putnbr_fd.c  libft/ft_strdup.c  libft/ft_strlen.c  libft/ft_strrchr.c \
                    libft/ft_toupper.c libft/ft_calloc.c  libft/ft_isdigit.c libft/ft_memchr.c  libft/ft_memset.c  \
                    libft/ft_putstr_fd.c  libft/ft_strjoin.c libft/ft_strmapi.c libft/ft_strtrim.c

OBJS	        = $(SRCS:.c=.o)
OBJSB			= $(LIBFT:.c=.o)
CC     			= gcc
CFLAGS 			= -Wall -Wextra -Werror -I $(INC)
RM     			= rm -f
INC			    = ft_printf.h
INCB            = libft/libft.h

NAME    		= libftprintf.a

all:        	  $(NAME)

$(NAME):		  $(OBJS) $(OBJSB)
				  ar rcs $(NAME) $(OBJS) $(OBJSB)

clean:
				  $(RM) $(OBJS) $(OBJSB)

fclean:    		  clean
		          $(RM) $(NAME)

re:        		  fclean $(NAME)

.PHONY:    		  all clean fclean re
