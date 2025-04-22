/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_libft_funcs_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:39:10 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/22 20:50:28 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_inset(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strncpy(char *str, int start, int len)
{
	int		i;
	char	*res;

	if (!str)
		return (NULL);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len && str[start + i])
	{
		res[i] = str[start + i];
		++i;
	}
	while (i < len)
		res[i++] = '\0';
	return (res);
}
