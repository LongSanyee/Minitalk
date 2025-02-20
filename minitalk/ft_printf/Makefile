SRCS = ft_printf.c ft_printhexalower.c ft_printhexaupper.c ft_printunsigned.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_printaddress.c
OBJS = ${SRCS:.c=.o}
LIBC = ar rcs
CFLAGS = -Wall -Wextra -Werror
CC = cc 
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) 
	${LIBC} ${NAME} ${OBJS}

%.o: %.c ft_printf.h
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all