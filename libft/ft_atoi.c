/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:22:34 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/30 23:22:34 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] && ft_isdigit(str[i]))
	{
		if (sign == 1 && res > (INT_MAX - (str[i] - '0')) / 10)
			return (0);
		else if (sign == -1 && res > (-(INT_MIN + (str[i] - '0'))) / 10)
			return (0);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] && !(ft_isdigit(str[i])))
		return (0);
	return (sign * res);
}
