/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:41:02 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/29 16:08:15 by rbarkhud         ###   ########.fr       */
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

static void	fill_stack(t_stack *stack, char **split)
{
	int		i;
	t_node	*new_node;

	i = 0;
	while (split[i])
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

t_stack	*init_stack(char **split)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->a = NULL;
	stack->b = NULL;
	fill_stack(stack, split);
	return (stack);
}

int	stack_length(t_stack *stack)
{
	int		size;
	t_node	*tmp;

	if (!stack || !stack->a)
		return (0);
	size = 0;
	tmp = stack->a;
	while (tmp)
	{
		++size;
		tmp = tmp->next;
	}
	return (size);
}
