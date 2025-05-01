/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:58:26 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/05/01 17:44:58 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static int	exec_instruction(char *inst, t_stack *stack)
{
	if (!ft_strcmp("pa\n", inst))
		return (pa(&stack, 0), 1);
	else if (!ft_strcmp("pb\n", inst))
		return (pb(&stack, 0), 1);
	else if (!ft_strcmp("ra\n", inst))
		return (ra(&stack, 0), 1);
	else if (!ft_strcmp("rb\n", inst))
		return (rb(&stack, 0), 1);
	else if (!ft_strcmp("rr\n", inst))
		return (rr(&stack, 0), 1);
	else if (!ft_strcmp("rra\n", inst))
		return (rra(&stack, 0), 1);
	else if (!ft_strcmp("rrb\n", inst))
		return (rrb(&stack, 0), 1);
	else if (!ft_strcmp("rrr\n", inst))
		return (rrr(&stack, 0), 1);
	else if (!ft_strcmp("sa\n", inst))
		return (sa(&stack, 0), 1);
	else if (!ft_strcmp("sb\n", inst))
		return (sb(&stack, 0), 1);
	else if (!ft_strcmp("ss\n", inst))
		return (ss(&stack, 0), 1);
	else
		return (0);
}

int	is_stack_sorted(t_stack	*stack)
{
	char	*instruction;
	t_node	*tmp;

	tmp = stack->a;
	while (1)
	{
		instruction = get_next_line(STDIN_FILENO);
		if (!instruction)
			break ;
		if (!exec_instruction(instruction, stack))
		{
			get_next_line(-1);
			free(instruction);
			return (-1);
		}
		free(instruction);
	}
	while (tmp->next)
	{
		if (tmp->val > tmp->next->val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	atoi_check(char *str)
{
	int	val;
	int	str_len;

	val = ft_atoi(str);
	str_len = ft_strlen(str);
	if (val == 0 && str_len > 1)
		return (0);
	if (val && str_len > 1 && ft_inset("+-", str[str_len - 1]))
		return (0);
	return (1);
}
