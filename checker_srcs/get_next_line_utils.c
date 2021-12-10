/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:58:43 by ebalsami          #+#    #+#             */
/*   Updated: 2021/05/22 16:58:45 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

t_list	*ft_list_new_element(int fd)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (0);
	list->memory = 0;
	list->fd = fd;
	list->next = 0;
	return (list);
}

void	ft_list_delete_element(t_list **list, int fd)
{
	t_list	*prev;
	t_list	*tmp;

	prev = 0;
	tmp = *list;
	while (tmp && tmp->fd != fd)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (!tmp)
		return ;
	if (prev)
		prev->next = tmp->next;
	else
		*list = tmp->next;
	free(tmp->memory);
	free(tmp);
}

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
		if (*s++ == (unsigned char)c)
			return ((char *)--s);
	if ((unsigned char )c == 0)
		return ((char *)s);
	return (0);
}

char	*ft_custom_strjoin(char *s1, char *s2)
{
	char	*p;
	char	*tmp;

	p = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (char));
	if (!p)
		return (0);
	tmp = p;
	if (s1)
		while (*s1)
			*tmp++ = *s1++;
	if (s2)
		while (*s2)
			*tmp++ = *s2++;
	*tmp = 0;
	return (p);
}
