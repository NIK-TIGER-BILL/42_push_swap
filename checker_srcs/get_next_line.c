#include "../includes/get_next_line.h"

void	ft_custom_lstadd_elem(t_list **lst, t_list *new)
{
	t_list	*begin;

	if (!new)
		return ;
	if (*lst)
	{
		begin = *lst;
		while ((*lst)->next)
			*lst = (*lst)->next;
		(*lst)->next = new;
		*lst = begin;
	}
	else
		*lst = new;
}

int	read_line(t_list *file_struct)
{
	char	*buf;
	char	*tmp;
	int		result;

	if (file_struct->content && ft_custom_strchr(file_struct->content, '\n'))
		return (1);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	result = 1;
	while (result)
	{
		result = read(file_struct->fd, buf, BUFFER_SIZE);
		if (result <= 0)
			break ;
		buf[result] = 0;
		tmp = file_struct->content;
		file_struct->content = ft_custom_strjoin(file_struct->content, buf);
		free(tmp);
		if (ft_custom_strchr(file_struct->content, '\n'))
			break ;
	}
	free(buf);
	return (result);
}

char	*fill_line(t_list *file_struct)
{
	int		len;
	char	*line;

	len = 0;
	if (!file_struct->content)
		return (0);
	while (file_struct->content && file_struct->content[len] != '\n')
		len++;
	line = (char *)malloc(len + 1);
	if (!line)
		return (0);
	len = 0;
	while (file_struct->content[len] != '\n')
	{
		line[len] = file_struct->content[len];
		len++;
	}
	line[len] = 0;
	return (line);
}

int	free_struct(t_list **file_struct, char **line)
{
	t_list	*tmp;
	t_list	*previous;

	tmp = *file_struct;
	if ((*file_struct)->result == 0)
	{
		(*file_struct) = (*file_struct)->next;
		*line = ft_custom_strdup(tmp->content);
		free(tmp->content);
		free(tmp);
	}
	else
	{
		while (tmp->next && tmp->result != 0)
		{
			previous = tmp;
			tmp = tmp->next;
		}
		previous->next = tmp->next;
		*line = ft_custom_strdup(tmp->content);
		free(tmp->content);
		free(tmp);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static t_list	*file_struct;
	t_list			*tmp;
	char			*del;

	if (!line || BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) == -1)
		return (-1);
	if (!file_struct)
		ft_custom_lstadd_elem(&file_struct, ft_custom_lst_new_elem(fd));
	tmp = file_struct;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (!tmp)
		ft_custom_lstadd_elem(&file_struct, ft_custom_lst_new_elem(fd));
	tmp = file_struct;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	tmp->result = read_line(tmp);
	if (tmp->result > 0)
		*line = fill_line(tmp);
	if (tmp->result == 0)
		return (free_struct(&file_struct, line));
	del = tmp->content;
	tmp->content = ft_custom_strdup(ft_custom_strchr(del, '\n') + 1);
	free(del);
	return (1);
}
