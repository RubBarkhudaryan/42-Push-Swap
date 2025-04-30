/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:36:43 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/30 16:38:59 by rbarkhud         ###   ########.fr       */
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

static int	pos_in_list(int index, t_node *list)
{
	int	i;
	t_node	*tmp;

	tmp = list;
	i = 0;
	while (tmp)
	{
		if (tmp->index == index)
			return (i);
		++i;
		tmp = tmp->next;
	}
	return (-1);
}

static int	max_index(t_node *list)
{
	int		max;
	int		index;
	t_node	*tmp;

	tmp = list;
	index = tmp->index;
	max = tmp->val;
	while (tmp)
	{
		if (max < tmp->val)
		{
			index = tmp->index;
			max = tmp->val;
		}
		tmp = tmp->next;
	}
	return (index);
}

void	sort_max(t_stack *stack, int n)
{
	int	index;
	int	pos;

	while (stack->b)
	{
		index = max_index(stack->b);
		pos = pos_in_list(index, stack->b);
		if (pos < n / 2)
		{
			while (stack->b->index != index)
				rb(&stack, 1);
		}
		else
		{
			while (stack->b->index != index)
				rrb(&stack, 1);
		}
		pa(&stack);
		--n;
	}
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
			pb(&stack);
			rb(&stack, 1);
			++counter;
		}
		else if (stack->a->index <= (counter + n))
		{
			pb(&stack);
			++counter;
		}
		else
			ra(&stack, 1);
	}
	sort_max(stack, len);
}
