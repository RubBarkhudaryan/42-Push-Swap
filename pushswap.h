/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:14:18 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/22 20:52:02 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H

# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				val;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*a;
	t_node	*b;
}	t_stack;

/*libft functions*/
int		ft_atoi(char *str);
int		ft_inset(char *str, char c);
int		ft_strlen(char *str);
int		ft_strcmp(char *str1, char *str2);
int		ft_isdigit(int c);
int		ft_isalpha(int c);

char	*ft_strdup(char *str);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strncpy(char *str, int start, int end);
char	**ft_split(char *str);
char	*ft_substr(char *str, unsigned int start, size_t len);

/*push swap utils*/
int		is_valid_arg(char **str, int len);
int		stack_length(t_node *stack);

char	*join_args(int argc, char **argv);
char	**split_args(int argc, char **argv);
t_stack	*init_stack(char **split);

void	ft_error(char **split);
void	free_split(char ***split);
void	free_stack(t_stack *stack);
void	print_operation(char *operation);

/*swap instructions*/
void	sa(t_stack **stack, int print);
void	sb(t_stack **stack, int print);
void	ss(t_stack **stack);

/*push instructions*/
void	pa(t_stack **stack);
void	pb(t_stack **stack);

/*rotate instructions*/
void	ra(t_stack **stack, int print);
void	rb(t_stack **stack, int print);
void	rr(t_stack **stack);

/*reverse rotate instructions*/
void	rra(t_stack **stack, int print);
void	rrb(t_stack **stack, int print);
void	rrr(t_stack **stack);

/*push swap sorting algorithms*/
void	sort_stack(t_stack *stack);
void	sort_2(t_stack *stack);
void	sort_3(t_stack *stack);
void	sort_4(t_stack *stack);
void	sort_5(t_stack **stack);
void	assign_indexes(t_node *head);
void	butterfly_sort(t_stack *stack, int len);

#endif