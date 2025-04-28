/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_little_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 23:59:54 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/29 01:23:06 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack*	sort_2(t_stack *stack)
{
	if (stack->a->val > stack->a->next->val)
		sa(&stack, 1);
	return (stack);
}

// t_stack*	sort_3(t_stack *stack)
// {
// 	int	a;
// 	int	b;
// 	int	c;

// 	a = (*stack)->a->val;
// 	b = (*stack)->a->next->val;
// 	c = (*stack)->a->next->next->val;

// 	if (a > b && b < c && a < c)
// 		sa(stack, 1);
// 	else if (a > b && b > c && a > c)
// 	{
// 		sa(stack, 1);
// 		rra(stack, 1);
// 	}
// 	else if (a > b && b < c && a > c)
// 		ra(stack, 1);
// 	else if (a < b && b > c && a < c)
// 	{
// 		sa(stack, 1);
// 		ra(stack, 1);
// 	}
// 	else if (a < b && b > c && a > c)
// 		rra(stack, 1);
// 	return (stack);
// }

