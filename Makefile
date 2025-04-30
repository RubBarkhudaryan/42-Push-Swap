NAME		=	push_swap
CHECKER		=	checker

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g3

SRCS		=	src/ps_main.c\
				src/ps_validation.c src/ps_utils.c src/ps_init_stack.c\
				src/ps_sort_stack.c src/ps_sort_little_stack.c src/ps_sort_utils.c\
				src/ps_indexation.c\
				src/ps_push_operations.c src/ps_swap_operations.c src/ps_rotate_operations.c src/ps_reverse_rotate_operations.c

BSRCS		=	bonus/main_bonus.c\
				bonus/init_stack_bonus.c bonus/utils_2_bonus.c bonus/utils_bonus.c bonus/validation_bonus.c \
				bonus/push_operation_bonus.c bonus/reverse_rotate_operations_bonus.c \
				bonus/rotate_operations_bonus.c bonus/swap_operations_bonus.c

OBJS		=	$(SRCS:%.c=%.o)
BOBJS		=	$(BSRCS:%.c=%.o)

all: $(NAME)

$(NAME) : $(OBJS)
	make -C ./libft
	make -C ./libft clean
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

bonus: $(CHECKER)

$(CHECKER): $(BOBJS)
	make -C ./libft
	make -C ./libft clean
	$(CC) $(CFLAGS) $(BOBJS) ./libft/libft.a -o $(CHECKER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(BOBJS)

fclean: clean
	rm -rf $(NAME) $(CHECKER) ./libft/libft.a

re: fclean all

.PHONY: all clean fclean re bonus