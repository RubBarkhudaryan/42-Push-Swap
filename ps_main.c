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

static t_stack	*sort(t_stack *stack)
{
	int	len;

	len = stack_length(stack);
	if (len == 1)
		return (stack);
	else if (len == 2)
		return sort_2(stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	char	**split;

	if (argc >= 2 && is_valid_arg(argv, argc))
	{
		split = split_args(argc, argv);
		free_split(&split);
		// stack = init_stack(split, argc - 1);
	}
	else
		ft_error(NULL, NULL);
	return (0);
}
