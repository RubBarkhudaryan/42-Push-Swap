/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:28:58 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/30 23:28:58 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *str1, char *str2)
{
	char	*res;
	int		i;
	int		j;

	if (!str1 && !str2)
		return (NULL);
	if (!str1)
		return (ft_substr(str2, 0, ft_strlen(str2)));
	if (!str2)
		return (ft_substr(str1, 0, ft_strlen(str1)));
	res = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 2);
	if (!res)
		return (NULL);
	i = -1;
	while (str1[++i])
		res[i] = str1[i];
	if (i > 0)
		res[i++] = ' ';
	j = -1;
	while (str2[++j])
		res[i + j] = str2[j];
	res[i + j] = '\0';
	return (res);
}
