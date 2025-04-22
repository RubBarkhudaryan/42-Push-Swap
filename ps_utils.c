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

void	error_msg(void)
{
	write (2, "Error\n", 6);
}

void	free_split(char ***split, int target_ind)
{
	int	i;

	if (!*split)
		return ;
	i = 0;
	while (i <= target_ind)
	{
		free((*split)[i]);
		++i;
	}
	free(*split);
}
