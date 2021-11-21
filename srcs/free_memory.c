#include "../includes/push_swap.h"

void	free_stack(t_stack **stack)
{
	while (*stack) // todo плохая не эффективная практика
		roundlst_delfirst(stack);
}

void 	free_double_array(char **split, int i)
{
	while (i >= 0)
	{
		free(split[i]);
		i--; // todo лишняя строка можно объяденить с 13 строкой
	}
	free(split);
}

void 	free_full_double_array(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
