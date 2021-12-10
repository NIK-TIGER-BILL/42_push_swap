/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:58:43 by ebalsami          #+#    #+#             */
/*   Updated: 2021/05/22 16:58:45 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_custom_atoi(int *final, const char *str)
{
	int				minus;
	int				tmp;

	minus = 1;
	*final = 0;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			minus = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		tmp = *final;
		*final *= 10;
		*final += *str - 48;
		if (tmp > *final)
			return (1);
		str++;
	}
	*final *= minus;
	return (0);
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
	int	len;

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
	int	last;

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
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 == *s2);
}
