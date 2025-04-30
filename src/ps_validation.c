/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:38:27 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/23 18:38:27 by rbarkhud         ###   ########.fr       */
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
	int	k;
	int	t;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			k = 0;
			t = 0;
			while (str[i][k] && (str[i][k] == '+'))
				++k;
			while (str[j][t] && (str[j][t] == '+'))
				++t;
			if (ft_strcmp(str[i] + k, str[j] + t) == 0)
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}

static int	contains_only(char *set, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_inset(set, str[i]))
			return (0);
		++i;
	}
	return (1);
}

char	*join_args(int argc, char **argv)
{
	int		i;
	char	*tmp;
	char	*join;

	i = 0;
	join = NULL;
	while (++i < argc)
	{
		if (contains_only("\t\n ", argv[i]) || (ft_strcmp("", argv[i]) == 0))
			return (free(join), NULL);
		if (!join)
			join = ft_strdup(argv[i]);
		else
		{
			tmp = ft_strjoin(join, " ");
			free(join);
			if (!tmp)
				return (NULL);
			join = ft_strjoin(tmp, argv[i]);
			free(tmp);
		}
		if (!join)
			return (NULL);
	}
	return (join);
}

int	is_valid_arg(char **str, int len)
{
	int		i;
	t_line	l;

	l.join = join_args(len, str);
	if (!l.join)
		return (0);
	l.sp = ft_split(l.join);
	free(l.join);
	i = -1;
	while (l.sp[++i])
	{
		if (contains_alpha(l.sp[i]))
			return (ft_error(l.sp), 0);
		if (ft_strlen(l.sp[i]) > 1 && l.sp[i][0] == '0')
			return (ft_error(l.sp), 0);
		if ((ft_atoi(l.sp[i]) == 0 && ft_strlen(l.sp[i]) > 1) || \
	(ft_atoi(l.sp[i]) && ft_strlen(l.sp[i]) > 1 && \
	ft_inset("+-", l.sp[i][ft_strlen(l.sp[i]) - 1])))
			return (ft_error(l.sp), 0);
		if ((ft_strcmp(l.sp[i], "-") == 0) || (ft_strcmp(l.sp[i], "+") == 0))
			return (ft_error(l.sp), 0);
	}
	if (contains_duplicate(l.sp))
		return (ft_error(l.sp), 0);
	return (free_split(&l.sp), 1);
}
