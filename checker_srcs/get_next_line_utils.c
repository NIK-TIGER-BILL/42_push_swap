#include "../includes/get_next_line.h"

char	*ft_custom_strchr(char *s, int c)
{
	char	*s2;

	s2 = (char *)s;
	while (*s2)
	{
		if (*s2 == (char)c)
			return (s2);
		s2++;
	}
	if (*s2 == (char)c)
		return (s2);
	return (0);
}

char	*ft_custom_strjoin(char *content, char *buf)
{
	char	*joiner;
	char	*tmp;

	joiner = (char *)malloc(ft_custom_strlen(content) + ft_custom_strlen(buf) +
			1);
	tmp = joiner;
	if (content)
		while (*content)
			*joiner++ = *content++;
	if (buf)
		while (*buf)
			*joiner++ = *buf++;
	*joiner = 0;
	return (tmp);
}

int	ft_custom_strlen(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count] != 0)
		count++;
	return (count);
}

char	*ft_custom_strdup(char *s1)
{
	char	*mem;
	int		counter;

	counter = 0;
	if (!s1)
	{
		mem = malloc(1);
		mem[0] = 0;
		return (mem);
	}
	mem = (char *)malloc(ft_custom_strlen(s1) + 1);
	if (!mem)
		return (0);
	while (counter <= ft_custom_strlen(s1))
	{
		mem[counter] = s1[counter];
		counter++;
	}
	return (mem);
}

t_list	*ft_custom_lst_new_elem(int fd)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (0);
	elem->content = 0;
	elem->fd = fd;
	elem->next = 0;
	elem->result = 1;
	return (elem);
}
