CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c render.c verify_endgame.c ft_free_matriz.c
OBJS = $(SRCS:.c=.o)
NAME = tic_tac_toe

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
