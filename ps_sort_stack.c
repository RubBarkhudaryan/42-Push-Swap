/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:36:43 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/29 20:34:17 by rbarkhud         ###   ########.fr       */
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

static int	rot_frwd(t_node *node, int target_idx, int size)
{
	int	steps;

	steps = 0;
	while (node && node->index != target_idx)
	{
		node = node->next;
		++steps;
	}
	return (steps <= size / 2);
}

static void	reverse_push(t_stack *stack, int max_idx)
{
	int	rotate_forward;

	while (stack->b)
	{
		rotate_forward = rot_frwd(stack->b, max_idx, stack_length(stack->b));
		if (rotate_forward)
			while (stack->b->index != max_idx)
				rb(&stack, 1);
		else
			while (stack->b->index != max_idx)
				rrb(&stack, 1);
		pa(&stack);
		max_idx--;
	}
}

void	butterfly_sort(t_stack *stack)
{
	int	size;
	int	counter;
	int	total;

	total = stack_length(stack->a);
	size = chunk_size(total);
	counter = 0;
	while (stack->a)
	{
		if (stack->a->index <= counter + size)
		{
			pb(&stack);
			if (stack->a->index <= counter)
				rb(&stack, 1);
			counter++;
		}
		else
			ra(&stack, 1);
	}
	reverse_push(stack, total - 1);
}