SRC = server.c
SRC1 = client.c utils.c
NAME = server
NAME1 = client
CFLAGS = -Wall -Werror -Wextra
CC = cc
OBJS = ${SRC:.c=.o}
OBJS1 = ${SRC1:.c=.o}
PRINTF = ./ft_printf/libftprintf.a

all: $(NAME) $(NAME1)

$(NAME): $(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)

$(NAME1): $(OBJS1)
	$(CC) $(CFLAGS) $(OBJS1) $(PRINTF) -o $(NAME1)

$(PRINTF):
	$(MAKE) -C ./ft_printf

%.o : %.c minitalk.h ./ft_printf/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJS1)

fclean: clean
	rm -rf $(NAME) $(NAME1) $(PRINTF)
	$(MAKE) -C ./ft_printf clean

re: fclean all