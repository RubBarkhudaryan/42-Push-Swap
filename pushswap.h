/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:14:18 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/22 20:52:02 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H

# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>

/*libft functions*/
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_strlen(char *str);
int		ft_inset(char *str, char c);

char	*ft_strncpy(char *str, int start, int end);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strdup(char *str);
char	**ft_split(char *str);

/*push swap utils*/
void	error_msg(void);

#endif