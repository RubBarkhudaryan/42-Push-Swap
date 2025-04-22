/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_libft_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:13:06 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/22 20:27:47 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		++i;
	return (i);
}

char	*ft_strjoin(char **str1, char *str2)
{
	char	*res;
	int		i;
	int		j;

	if (!*str1 && !str2)
		return (NULL);
	if (!str1)
		return (ft_substr(str2, 0, ft_strlen(str2)));
	if (!str2)
		return (ft_substr(*str1, 0, ft_strlen(*str1)));
	res = (char *)malloc(ft_strlen(*str1) + ft_strlen(str2) + 1);
	if (!res)
		return (NULL);
	i = -1;
	while ((*str1)[++i])
		res[i] = (*str1)[i];
	if (i > 0)
		res[i++] = ' ';
	j = -1;
	while (str2[++j])
		res[i + j] = str2[j];
	res[i + j] = '\0';
	return (free(*str1), res);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*dup;

	dup = (char *)malloc(ft_strlen(str) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		++i;
	}
	dup[i] = '\0';
	return (dup);
}
