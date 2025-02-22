SRC = server.c ft_putnbr.c
SRC1 = client.c utils.c ft_putnbr.c
NAME = server
NAME1 = client
CFLAGS = -Wall -Werror -Wextra
CC = cc
OBJS = ${SRC:.c=.o}
OBJS1 = ${SRC1:.c=.o}

all: $(NAME) $(NAME1)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAME1): $(OBJS1)
	$(CC) $(CFLAGS) $(OBJS1) -o $(NAME1)

%.o : %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJS1)

fclean: clean
	rm -rf $(NAME) $(NAME1)

re: fclean all