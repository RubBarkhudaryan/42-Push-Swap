/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_indexation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:28:35 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/29 19:34:51 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	assign_indexes(t_node *head)
{
	int		index;
	t_node	*current;
	t_node	*temp_head;

	temp_head = head;
	while (head)
	{
		current = temp_head;
		index = 0;
		while (current)
		{
			if (head->val > current->val)
				index++;
			current = current->next;
		}
		head->index = index;
		head = head->next;
	}
}
