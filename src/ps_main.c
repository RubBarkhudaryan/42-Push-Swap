/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:13:54 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/22 20:50:57 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_stack(t_stack *stack)
{
	int	len;

	assign_indexes(stack->a);
	len = stack_length(stack->a);
	if (len == 1)
		return ;
	else if (len == 2)
		sort_2(stack);
	else if (len == 3)
		sort_3(stack);
	else if (len == 4)
		sort_4(stack);
	else if (len == 5)
		sort_5(&stack);
	else
		butterfly_sort(stack, len);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	char	**split;

	if (argc >= 2 && is_valid_arg(argv, argc))
	{
		split = split_args(argc, argv);
		stack = init_stack(split);
		sort_stack(stack);
		free_split(&split);
		free_stack(stack);
	}
	else
		ft_error(NULL);
	return (0);
}
