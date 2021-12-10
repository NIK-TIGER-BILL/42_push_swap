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

char	*str_prolongate_fabrik(char *arr, char *add)
{
	char	*tmp;

	tmp = arr;
	arr = ft_strjoin(arr, add);
	free(tmp);
	if (!arr)
		my_exit(-2);
	return (arr);
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
