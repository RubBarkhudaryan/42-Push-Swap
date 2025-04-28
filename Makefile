NAME	=	push_swap

CC		=	cc
CFLAGS	=	 -g

SRCS	=	ps_main.c\
			ps_validation.c ps_utils.c ps_init_stack.c ps_sort_stack.c ps_sort_little_stack.c\
			ps_ft_split.c ps_libft_funcs.c ps_libft_funcs_2.c\
			ps_push_operations.c ps_swap_operations.c ps_rotate_operations.c ps_reverse_rotate_operations.c

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