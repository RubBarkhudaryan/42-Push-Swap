NAME	=	pushswap

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	ps_main.c ps_validation.c ps_utils.c ps_libft_funcs.c ps_libft_funcs_2.c\
			ps_ft_split.c

OBJS	=	$(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -g

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re