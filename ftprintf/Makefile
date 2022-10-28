# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 17:57:43 by domy              #+#    #+#              #
#    Updated: 2022/05/17 20:36:40 by dallocca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = ./libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
SRCS = *.c
OBJS = $(SRCS:.c=.o)

$(NAME):	
			make -C ./libft
			cp libft/libft.a $(NAME)
			$(CC) $(CFLAGS) -c $(SRCS)
			$(AR) $(NAME) $(OBJS)
			ranlib $(NAME)

all: 		$(NAME)

clean:
			make clean -C libft
			$(RM) $(OBJS)

fclean: 
			make fclean -C libft
			$(RM) $(NAME)
			$(RM) $(OBJS)

re: 		fclean all

.PHONY: 	bonus all clean fclean re












