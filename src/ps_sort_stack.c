/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:36:43 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/05/01 02:01:44 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	chunk_size(int nb)
{
	int	sqrt;
	int	log;
	int	result;

	sqrt = 1;
	if (nb <= sqrt)
		return (sqrt);
	while (sqrt * sqrt < nb)
		++sqrt;
	log = 0;
	result = 1;
	while (result < nb)
	{
		result *= 2;
		++log;
	}
	return (sqrt + log - 1);
}

void	butterfly_sort(t_stack *stack, int len)
{
	int	counter;
	int	n;

	n = chunk_size(len);
	counter = 0;
	stack->b = NULL;
	while (stack->a)
	{
		if (stack->a->index <= counter)
		{
			pb(&stack, 1);
			rb(&stack, 1);
			++counter;
		}
		else if (stack->a->index <= (counter + n))
		{
			pb(&stack, 1);
			++counter;
		}
		else
			ra(&stack, 1);
	}
	sort_max(stack, len);
}
