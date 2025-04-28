/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:41:02 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/28 19:39:48 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	push_back(t_node **lst, t_node *node)
{
	t_node	*temp;

	if (!lst || !node)
		return ;
	if (!*lst)
	{
		*lst = node;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
}

static void	fill_stack(t_stack *stack, int len, char **split)
{
	int		i;
	t_node	*new_node;

	i = 0;
	while (i < len)
	{
		new_node = malloc(sizeof(t_node));
		if (!new_node)
			return ;
		new_node->val = ft_atoi(split[i]);
		new_node->next = NULL;
		push_back(&stack->a, new_node);
		++i;
	}
}

t_stack	*init_stack(char **split, int len)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->a = NULL;
	stack->b = NULL;
	fill_stack(stack, len, split);
	return (stack);
}

int	stack_length(t_stack *stack)
{
	int	size;

	if (!stack || !stack->a)
		return (0);
	size = 0;
	while (stack->a)
	{
		++size;
		stack->a = stack->a->next;
	}
	return (size);
}
