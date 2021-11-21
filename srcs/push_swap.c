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
	long int		tmp;
	int				*cash;

	counter = 0; // todo лишняя переменная
	while (set[counter])
		counter++;
	cash = (int *)malloc(sizeof(int *) * counter); // todo почему (int *) а не (int)
	if (!cash)
		my_exit(-1); // todo нужно код -2, а не -1
	*save = counter;
	index = 0; // todo почему не сделать -1, как делалось в других функциях validator.c строка 13-14 (должен быть одинаковый синтаксис)
	while (set[index])
	{
		tmp = ft_atoi_long(set[index]); // todo логику строки 30 можно вовнутрь
		if (tmp > 2147483647 || tmp < -2147483648) // todo не нравится
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
	stack_init(cash, counter); // todo не очень название функции. По названию она только инициализирует стак, а где выполняется все остальное?
	return (0);
}
