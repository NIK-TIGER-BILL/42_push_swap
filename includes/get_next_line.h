#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include "../includes/libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif
typedef struct s_list
{
	int				fd;
	char			*content;
	int				result;
	struct s_list	*next;
}	t_list;
int		get_next_line(int fd, char **line);
char	*ft_free_strjoin(char *s1, char *s2);
char	*ft_custom_strjoin(char *content, char *buf);
t_list	*ft_custom_lst_new_elem(int fd);
char	*ft_custom_strdup(char *s1);
char	*ft_custom_strchr(char *s, int c);
int		ft_custom_strlen(char *str);

#endif
