/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:58:43 by ebalsami          #+#    #+#             */
/*   Updated: 2021/05/22 16:58:45 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	my_exit(int err_num)
{
	if (err_num == -1)
		ft_putstr_fd("Error\n", 1);
	if (err_num == -2)
		ft_putstr_fd("Malloc problem\n", 1);
	exit (0);
}

int	*casher(char **set, int *save)
{
	unsigned int	counter;
	unsigned int	index;
	int				tmp;
	int				*cash;

	counter = 0;
	while (set[counter])
		counter++;
	cash = (int *)malloc(sizeof(int *) * counter);
	if (!cash)
		my_exit(-1);
	*save = counter;
	index = 0;
	while (set[index])
	{
		if (ft_custom_atoi(&tmp, set[index]))
			my_exit(-1);
		cash[index] = tmp;
		index++;
	}
	return (cash);
}

int	main(int argc, char **argv)
{
	int	*cash;
	int	counter;

	counter = 0;
	if (argc > 1)
		counter += check_arguments(argc, argv, &cash);
	else
		return (0);
	if (counter == -1)
	{
		free(cash);
		my_exit(-2);
	}
	stack_init(cash, counter);
	return (0);
}
