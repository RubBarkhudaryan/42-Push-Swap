/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ft_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:29:49 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/22 20:53:28 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	words_count(char *str)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		while (ft_inset(str[i], "\n\t "))
			++i;
		while (!ft_inset(str[i], "\n\t "))
		{
			++in_word;
			++i;
		}
		if (in_word)
		{
			in_word = 0;
			++count;
		}
		if (str[i + 1])
			++i;
	}
	return (count);
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	char	**split;

	split = (char **)malloc(sizeof(char *) * (words_count(str) + 1));
}
