NAME = server
NAMEC = client

SRCS = server.c client.c
OBJ = $(SRCS:.c=.o)
LIBFT = libft/libft.a
CC = cc -g
CFLAGS = -Wall -Wextra -Werror -fsanitize=address

all: $(LIBFT) $(NAME) $(NAMEC)

$(NAME): $(LIBFT) server.o
	$(CC) $(CFLAGS) server.o $(LIBFT) -o $(NAME)

$(NAMEC): client.o
	$(CC) $(CFLAGS) client.o $(LIBFT) -o $(NAMEC)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

norm:
	norminette $(SRCS)

clean:
	rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	rm -f libft.a
	rm -f $(NAME) $(NAMEC)
	rm -f $(NAME_BONUS) $(NAMEC_BONUS)
	@make -C libft fclean

re: fclean all

.PHONY: all bonus norm clean fclean re
