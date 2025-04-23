/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:53:06 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/22 17:48:56 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_error(char **str)
{
	if (str)
		free_split(&str);
	write (2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_split(char ***split)
{
	int	i;

	if (!*split)
		return ;
	i = -1;
	while ((*split)[++i])
		free((*split)[i]);
	free(*split);
}

// t_stack	*format_arguments(char **argv, int argc)
// {
// 	char	*join;
// 	char	**split;

// 	join = join_args()
// }