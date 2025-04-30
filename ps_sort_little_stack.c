/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_little_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 23:59:54 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/30 18:08:44 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	find_min_position(t_node *stack)
{
	t_node	*tmp;
	int		pos;
	int		min;
	int		i;

	tmp = stack;
	min = tmp->val;
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->val < min)
		{
			min = tmp->val;
			pos = i;
		}
		tmp = tmp->next;
		++i;
	}
	return (pos);
}

void	sort_2(t_stack *stack)
{
	if (stack->a->val > stack->a->next->val)
		sa(&stack, 1);
}

void	sort_3(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->a->val;
	b = stack->a->next->val;
	c = stack->a->next->next->val;
	if (a > b && b < c && a < c)
		sa(&stack, 1);
	else if (a > b && b > c && a > c)
	{
		sa(&stack, 1);
		rra(&stack, 1);
	}
	else if (a > b && b < c && a > c)
		ra(&stack, 1);
	else if (a < b && b > c && a < c)
	{
		sa(&stack, 1);
		ra(&stack, 1);
	}
	else if (a < b && b > c && a > c)
		rra(&stack, 1);
}

void	sort_4(t_stack *stack)
{
	int	min_pos;

	min_pos = find_min_position(stack->a);
	if (min_pos == 1)
		ra(&stack, 1);
	else if (min_pos == 2)
	{
		ra(&stack, 1);
		ra(&stack, 1);
	}
	else if (min_pos == 3)
		rra(&stack, 1);
	pb(&stack, 1);
	sort_3(stack);
	pa(&stack, 1);
}

void	sort_5(t_stack **stack)
{
	int	min_pos;

	min_pos = find_min_position((*stack)->a);
	if (min_pos == 1)
		ra(stack, 1);
	else if (min_pos == 2)
	{
		ra(stack, 1);
		ra(stack, 1);
	}
	else if (min_pos == 3)
	{
		rra(stack, 1);
		rra(stack, 1);
	}
	else if (min_pos == 4)
		rra(stack, 1);
	pb(stack, 1);
	min_pos = find_min_position((*stack)->a);
	if (min_pos == 1)
		ra(stack, 1);
	else if (min_pos == 2)
	{
		ra(stack, 1);
		ra(stack, 1);
	}
	else if (min_pos == 3)
		rra(stack, 1);
	pb(stack, 1);
	sort_3(*stack);
	pa(stack, 1);
	pa(stack, 1);
}
