#include "../includes/push_swap.h"

long int	ft_atoi_long(const char *str)
{
	long int	final;
	int			minus;

	minus = 1;
	final = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
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

int	my_exit(int err_num)
{
	if (err_num == -1)
		ft_putstr_fd("Error\n", 1);
	if (err_num == -2)
		ft_putstr_fd("Malloc problem\n", 1);
	exit (0);
}

int	len_stack(t_stack *stack)
{
	int len;

	len = 0;
	if (!stack)
		return (0);
	len++;
	stack = stack->next;
	while (stack->head == 0)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

int	sorted_stack(t_stack *stack)
{
	int last;

	last = stack->previous->number;
	while (stack->number != last)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_custom_strcmp(char *s1, char *s2)
{
	int	len;

	if (ft_strlen(s1) > ft_strlen(s2))
		len = ft_strlen(s1);
	else
		len = ft_strlen(s2);
	while (len--)
	{
		if (*s1 != *s2)
			return (1);
		s1++;
		s2++;
	}
	return (0);
}
