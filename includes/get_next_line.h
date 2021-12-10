/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:58:50 by ebalsami          #+#    #+#             */
/*   Updated: 2021/05/22 16:58:51 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1000

typedef struct s_list
{
	int				fd;
	char			*memory;
	struct s_list	*next;
}					t_list;

int		get_next_line(int fd, char **line);

t_list	*ft_list_new_element(int fd);
void	ft_list_delete_element(t_list **list, int fd);
int		ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_custom_strjoin(char *s1, char *s2);

#endif
