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

int	is_valid_arg(char **str, int len)
{
	int		i;
	char	*args;
	char	**split;

	i = 0;
	args = ft_strdup("");
	while (++i < len)
		args = ft_strjoin(&args, str[i]);
	split = ft_split(args);
	i = 0;
	free(args);
	while (split[i])
	{
		if (contains_alpha(split[i]))
			return (free_split(&split, i), 0);
		if (ft_strlen(split[i]) > 1 && split[i][0] == '0')
			return (free_split(&split, i), 0);
		if (ft_atoi(split[i]) == 0 && ft_strlen(split[i]) > 1)
			return (free_split(&split, i), 0);
		++i;
	}
	if (contains_duplicate(split))
		return (free_split(&split, i), 0);
	return (free_split(&split, i), 1);
}
