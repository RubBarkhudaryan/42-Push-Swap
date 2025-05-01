/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 23:41:16 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/02/14 23:41:16 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*new_str;

	if (!str1 && !str2)
		return (NULL);
	if (!str1)
		return (ft_substr(str2, 0, ft_strlen(str2)));
	if (!str2)
		return (ft_substr(str1, 0, ft_strlen(str1)));
	new_str = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (str1[++i])
		new_str[i] = str1[i];
	j = -1;
	while (str2[++j])
		new_str[i + j] = str2[j];
	new_str[i + j] = '\0';
	return (free(str1), new_str);
}
