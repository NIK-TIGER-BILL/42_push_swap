/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:58:43 by ebalsami          #+#    #+#             */
/*   Updated: 2021/05/22 16:58:45 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_digits(char *argv)
{
	if (*argv == '-')
		argv++;
	while (*argv)
	{
		if (!isdigit(*argv))
			return (0);
		argv++;
	}
	return (1);
}

int	check_doubles(char **set)
{
	unsigned int	counter;

	while (*set)
	{
		counter = 1;
		while (set[counter])
		{
			if (ft_custom_strcmp(set[0], set[counter]))
				return (0);
			counter++;
		}
		set++;
	}
	return (1);
}

int	check_overfit(char *splitter)
{
	int	check;

	return (ft_custom_atoi(&check, splitter));
}
