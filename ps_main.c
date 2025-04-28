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

int	main(int argc, char **argv)
{
	t_stack	*stack;
	char	**split;

	split = NULL;
	if (argc >= 2 && is_valid_arg(argv, argc, &split))
	{
		stack = init_stack(split, argc - 1);
		free_split(&split);
		sort_2(stack);
		while (stack->a)
		{
			printf("val: %d\n", stack->a->val);
			stack->a = stack->a->next;
		}
	}
	else
		ft_error(NULL, NULL);
	return (0);
}
