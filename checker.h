/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:31:16 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/30 17:31:16 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H

# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "./pushswap.h"

int		is_stack_sorted(t_stack	*stack);
char	*get_next_line(int fd);
char	*ft_strchr(char *str, int c);
char	*get_strjoin(char *str1, char *str2);
#endif