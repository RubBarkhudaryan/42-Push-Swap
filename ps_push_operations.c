/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:56:43 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/26 20:02:33 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	push(t_node **in, t_node **out)
{
	t_node	*in_head;
	t_node	*out_head;

	if (!in || !*in)
		return (0);
	in_head = *in;
	*in = in_head->next;
	out_head = *out;
	in_head->next = out_head;
	*out = in_head;
	return (1);
}

void	pa(t_stack **stack)
{
	if (!push(&(*stack)->b, &(*stack)->a))
		return ;
	print_operation("pa\n");
}

void	pb(t_stack **stack)
{
	if (!push(&(*stack)->a, &(*stack)->b))
		return ;
	print_operation("pb\n");
}
