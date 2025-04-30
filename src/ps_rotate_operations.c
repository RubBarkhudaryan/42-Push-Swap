/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:16:19 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/30 18:12:15 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ra(t_stack **stack, int print)
{
	t_node	*head;
	t_node	*temp;

	if (!(*stack)->a || !(*stack)->a->next)
		return ;
	head = (*stack)->a;
	temp = (*stack)->a;
	while (temp->next)
		temp = temp->next;
	temp->next = head;
	(*stack)->a = head->next;
	head->next = NULL;
	if (print)
		print_operation("ra\n");
}

void	rb(t_stack **stack, int print)
{
	t_node	*head;
	t_node	*temp;

	if (!(*stack)->b || !(*stack)->b->next)
		return ;
	head = (*stack)->b;
	temp = (*stack)->b;
	while (temp->next)
		temp = temp->next;
	temp->next = head;
	(*stack)->b = head->next;
	head->next = NULL;
	if (print)
		print_operation("rb\n");
}

void	rr(t_stack **stack, int print)
{
	ra(stack, 0);
	rb(stack, 0);
	if (print)
		print_operation("rr\n");
}
