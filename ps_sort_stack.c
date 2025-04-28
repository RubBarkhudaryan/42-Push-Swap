/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:36:43 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/29 03:28:17 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	index_stack(t_stack *stack)
{
	t_node	*tmp;
	t_node	*compare;
	int		index;

	tmp = stack->a;
	while (tmp)
	{
		index = 0;
		compare = stack->a;
		while (compare)
		{
			if (compare->val < tmp->val)
				index++;
			compare = compare->next;
		}
		tmp->index = index;
		tmp = tmp->next;
	}
}

void	big_sort(t_stack **stack)
{
	int	size;
	int	max_bits;
	int	max_num;
	int	i;

	i = 0;
	max_bits = 0;
	max_num = size - 1;
	size = stack_length(*stack);
	while ((max_num >> max_bits) != 0)
		++max_bits;
	for (i = 0; i < max_bits; i++)
	{
		int	j = 0;
		while (j < size)
		{
			if ((((*stack)->a->index >> i) & 1) == 1)
				ra(stack, 1);
			else
				pb(stack);
			++j;
		}
		while ((*stack)->b)
			pa(stack);
	}
}
