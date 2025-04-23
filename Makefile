NAME	=	push_swap

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address

SRCS	=	ps_main.c ps_validation.c ps_utils.c ps_libft_funcs.c ps_libft_funcs_2.c\
			ps_ft_split.c

OBJS	=	$(SRCS:%.c=%.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re