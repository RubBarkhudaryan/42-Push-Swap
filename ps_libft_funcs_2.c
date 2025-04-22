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
	while (i <= len)
		res[i++] = '\0';
	return (res);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str1[i] || str2[j])
	{
		if (str1[i] != str2[j])
			return (str1[i] - str2[j]);
		++i;
		++j;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] && ft_inset("\n\t ", str[i]))
		++i;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		++i;
	}
	while (ft_isdigit(str[i]))
	{
		if (sign == 1 && res > (INT_MAX - (str[i] - '0')) / 10)
			return (0);
		else if (sign == -1 && res > (-(INT_MIN + (str[i] - '0'))) / 10)
			return (0);
		res = res * 10 + (str[i] - '0');
		++i;
	}
	return (sign * res);
}

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	strlen;
	size_t	i;

	i = 0;
	strlen = ft_strlen(str);
	if (start > strlen)
		return (ft_strdup(""));
	if (len > strlen - start)
		len = strlen - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	while (i < len && str[start + i])
	{
		substr[i] = str[start + i];
		++i;
	}
	substr[i] = '\0';
	return (substr);
}
