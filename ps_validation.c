/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:13:49 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/22 16:54:15 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	contains_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			return (1);
		++i;
	}
	return (0);
}

static int	contains_duplicate(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_strcmp(str[i], str[j]) == 0)
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}

int	is_valid_arg(char **str)
{
	int	i;

	if (contains_duplicate(str))
		return (0);
	i = 0;
	while (str[i])
	{
		if (contains_alpha(str[i]))
			return (0);
		if (ft_strlen(str[i]) > 1 && str[i][0] == '0')
			return (0);
		if (ft_atoi(str[i]) == 0 && ft_strlen(str[i]) > 1)
			return (0);
		++i;
	}
	return (1);
}
