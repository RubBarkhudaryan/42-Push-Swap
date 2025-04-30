NAME	=	push_swap
CHECKER	=	checker

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g3

SRCS	=	ps_main.c\
			ps_validation.c ps_utils.c ps_init_stack.c ps_sort_stack.c ps_sort_little_stack.c\
			ps_indexation.c\
			ps_ft_split.c ps_libft_funcs.c ps_libft_funcs_2.c\
			ps_push_operations.c ps_swap_operations.c ps_rotate_operations.c ps_reverse_rotate_operations.c

BSRCS	=	ch_main_bonus.c ch_stack_utils.c \
			get_next_line.c get_next_line_utils.c \
			ps_validation.c ps_utils.c ps_init_stack.c ps_sort_stack.c ps_sort_little_stack.c\
			ps_indexation.c\
			ps_ft_split.c ps_libft_funcs.c ps_libft_funcs_2.c\
			ps_push_operations.c ps_swap_operations.c ps_rotate_operations.c ps_reverse_rotate_operations.c

OBJS	=	$(SRCS:%.c=%.o)
BOBJS	=	$(BSRCS:%.c=%.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) -o $(CHECKER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re bonus