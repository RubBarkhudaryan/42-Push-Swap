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
# include <limits.h>
# include <stdio.h>

typedef struct stack
{
	int		val;
	struct stack	*next;
}	t_stack;

/*libft functions*/
int		ft_atoi(char *str);
int		ft_inset(char *str, char c);
int		ft_strlen(char *str);
int		ft_strcmp(char *str1, char *str2);
int		ft_isdigit(int c);
int		ft_isalpha(int c);

char	*ft_strdup(char *str);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strncpy(char *str, int start, int end);
char	**ft_split(char *str);
char	*ft_substr(char *str, unsigned int start, size_t len);

/*push swap utils*/
int		is_valid_arg(char **str, int len);

char	*join_args(int argc, char **argv);

void	ft_error(char **str);
void	free_split(char ***split);

t_stack	*format_arguments(char **argv, int argc);

#endif