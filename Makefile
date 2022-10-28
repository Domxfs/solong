CC = cc
NAME = so_long
CFLAGS = -Wall -Wextra -Werror
SRCS = utili/check.c \
	   utili/check2.c \
	   utili/immagine.c \
	   utili/mapgest.c \
	   utili/utils.c \
	   solong.c \
       get_next_line/get_next_line.c \
	   get_next_line/get_next_line_utils.c

MLX = -lmlx -framework OpenGL -framework AppKit

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C ftprintf
	$(CC) $(MLX) $(OBJS) -Lftprintf -lftprintf -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
