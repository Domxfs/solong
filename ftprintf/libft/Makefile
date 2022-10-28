# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 19:21:51 by domy              #+#    #+#              #
#    Updated: 2022/03/23 16:57:47 by dallocca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_strlen.c \
	   ft_strlcpy.c\
	   ft_strlcat.c\
	   ft_toupper.c\
	   ft_tolower.c\
	   ft_strchr.c\
	   ft_strncmp.c\
	   ft_strnstr.c\
	   ft_atoi.c\
	   ft_memmove.c\
	   ft_memset.c\
	   ft_memcmp.c\
	   ft_memchr.c\
	   ft_strdup.c\
	   ft_calloc.c\
	   ft_strrchr.c\
	   ft_strmapi.c\
	   ft_substr.c\
	   ft_strjoin.c\
	   ft_putchar_fd.c\
	   ft_putstr_fd.c\
	   ft_putendl_fd.c\
	   ft_putnbr_fd.c\
	   ft_striteri.c\
	   ft_itoa.c\
	   ft_split.c\
	   ft_strtrim.c\
	   
	   
OBJS	= $(SRCS:.c=.o)

RM		= rm -f

LIBC	= ar -rcs

FLAGS	= -Wall -Wextra -Werror

INCS	= .

.c.o :

	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}

$(NAME): ${OBJS}

	${LIBC} $(NAME) $(OBJS)

all: $(NAME)

fclean: clean

	$(RM) $(NAME) $(bonus)

clean:

	$(RM) -f $(OBJS) $(OBJS_B)

re: fclean all

.PHONY: all bonus clean fclean re .c.o