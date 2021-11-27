#include "../includes/push_swap.h"

long int	ft_atoi_long(const char *str) //todo лучше переписать функцию, здесь не нужно использование long
{
	long int	final;
	int			minus;

	minus = 1;
	final = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32)) // todo лучше писать не целочисленные значения char а как '0' - '9' для читаемости
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			minus = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		final *= 10;
		final += *str - 48;
		str++;
	}
	return (final * minus);
}

int	len_stack(t_stack *stack)
{
	int	len;

	if (!stack)
		return (0);
	len = 1;
	stack = stack->next;
	while (stack->head == 0)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 == *s2);
}

char	*str_prolongate_fabrik(char *arr, char *add)
{
	char	*tmp;

	tmp = arr;
	arr = ft_strjoin(arr, add);
	free(tmp);
	return (arr);
}

void	ft_putstr(char *s)
{
	if (s)
		while (*s)
			write(1, s++, 1);
}

