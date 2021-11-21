#include "../includes/push_swap.h"
int	check_digits(char *argv)
{
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
	long int	check;

	check = ft_atoi_long(splitter);
	if (check > 2147483647 || check < -2147483648)
		return (0);
	else
		return (1);
}

int	checkomba(char **splitter)
{
	int	i;

	i = -1;
	while (splitter[++i])
	{
		if (!check_digits(splitter[i]) && !check_overfit(splitter[i]))
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
	i = -1;
	while (splitter[++i])
		(*cash)[i] = ft_atoi_long(splitter[i]);
	free_double_array(splitter, i);
	return (i);
}
