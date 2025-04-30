/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:00:23 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/30 18:00:23 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"
#include <stdio.h>
// static void	print_stack(t_node *lst)
//  {
//  	t_node *tmp = lst;
//  	while (tmp)
//  	{
//  		printf("val: %d, index: %d\n", tmp->val, tmp->index);
//  		tmp = tmp->next;
//  	}
//  }

int main(int argc, char **argv)
{
	int		status;
	char	**split;
	t_stack	*stack;

	if (argc >= 2 && is_valid_arg(argv, argc))
	{
		split = split_args(argc, argv);
		stack = init_stack(split);
		free_split(&split);
		status = is_stack_sorted(stack);
		if (status)
			print_operation("OK\n");
		else if (!status)
			print_operation("KO\n");
		else
			print_operation("Error\n");
		free_stack(stack);
	}
	else
		ft_error(NULL);
	return (0);
}