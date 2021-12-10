/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
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
			if (ft_strcmp(set[0], set[counter]))
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

int	checkomba(char **splitter)
{
	int	i;

	i = -1;
	while (splitter[++i])
	{
		if (!check_digits(splitter[i]) || check_overfit(splitter[i]))
		{
			free_full_double_array(splitter);
			my_exit(-1);
		}
	}
	if (!check_doubles(splitter))
	{
		free_full_double_array(splitter);
		my_exit(-1);
	}
	return (i);
}

int	check_arguments(int argc, char **argv, int **cash)
{
	int		i;
	char	*arr;
	char	**splitter;

	i = 1;
	arr = ft_calloc(ft_strlen(argv[i]) + 1, 1);
	if (!arr)
		return (-1);
	ft_memcpy(arr, argv[i], ft_strlen(argv[i]));
	while (++i < argc)
	{
		arr = str_prolongate_fabrik(arr, " ");
		arr = str_prolongate_fabrik(arr, argv[i]);
	}
	splitter = ft_split(arr, ' ');
	free(arr);
	i = checkomba(splitter);
	*cash = malloc(sizeof(int *) * i);
	if (!*cash)
		return (-1);
	i = -1;
	while (splitter[++i])
		ft_custom_atoi(&(*cash)[i], splitter[i]);
	free_double_array(splitter, i);
	return (i);
}
