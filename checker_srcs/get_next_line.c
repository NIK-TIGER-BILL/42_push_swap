/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:58:35 by ebalsami          #+#    #+#             */
/*   Updated: 2021/05/22 16:58:38 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	check_line_in_memory(char **p, char **memory, char **line)
{
	char	*tmp;
	char	*tmp2;

	*p = ft_strchr(*memory, '\n');
	if (!*memory)
		return (1);
	tmp2 = *line;
	if (*p)
	{
		**p = 0;
		*line = ft_custom_strjoin(*memory, 0);
		tmp = *memory;
		*memory = ft_custom_strjoin(++(*p), 0);
		free(tmp);
		if (!*memory || !*line)
			return (0);
	}
	else
	{
		*line = *memory;
		*memory = 0;
	}
	free(tmp2);
	return (1);
}

int	write_data(char **storage, char *data)
{
	char	*tmp;

	tmp = *storage;
	*storage = ft_custom_strjoin(*storage, data);
	if (!*storage)
		return (0);
	free(tmp);
	return (1);
}

int	get_line_2(int fd, char *p, char **line, char **memory)
{
	char	buf[BUFFER_SIZE + 1];
	int		count;

	count = 0;
	if (!p)
		count = read(fd, buf, BUFFER_SIZE);
	while (!p && count > 0)
	{
		buf[count] = 0;
		p = ft_strchr(buf, '\n');
		if (p)
		{
			*p = 0;
			if (!write_data(memory, ++p))
				return (-1);
		}
		if (!write_data(line, buf))
			return (-1);
		if (!p)
			count = read(fd, buf, BUFFER_SIZE);
	}
	return (count);
}

int	get_line(int fd, char **line, char **memory)
{
	int		count;
	char	*p;

	*line = ft_custom_strjoin("", 0);
	if (!(check_line_in_memory(&p, memory, line)))
		return (-1);
	count = get_line_2(fd, p, line, memory);
	if (count == -1)
	{
		free(*line);
		*line = 0;
		return (-1);
	}
	if (!count && !*memory)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static t_list	*list;
	t_list			*tmp;
	int				result;

	*line = 0;
	if (read(fd, 0, 0) == -1 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!list)
		list = ft_list_new_element(fd);
	if (!list)
		return (-1);
	tmp = list;
	while (tmp && tmp->fd != fd)
	{
		if (!tmp->next)
			tmp->next = ft_list_new_element(fd);
		if (!tmp->next)
			return (-1);
		tmp = tmp->next;
	}
	result = get_line(tmp->fd, line, &tmp->memory);
	if (result < 1)
		ft_list_delete_element(&list, fd);
	return (result);
}
