/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:36:43 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/28 19:58:05 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_2(t_stack *stack)
{
	if (stack->a->val > stack->a->next->val)
		sa(&stack, 1);
}