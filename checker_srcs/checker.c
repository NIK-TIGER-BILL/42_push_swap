#include "../includes/push_swap.h"

t_stack	*stack_bild(int *cash, int counter)
{
	t_stack		*stack_A;

	stack_A = stack_constructor(cash, counter);
	free(cash);
	return (stack_A);
}

void	func_switcher(t_stack **stack_A, t_stack **stack_B, int counter)
{
	if (counter == 0)
		check_swap_a(stack_A);
	if (counter == 1)
		check_swap_both(stack_A, stack_B);
	if (counter == 2)
		check_swap_b(stack_B);
	if (counter == 3)
		check_shift_A(stack_A);
	if (counter == 4)
		check_shift_B(stack_B);
	if (counter == 5)
		check_shift_both(stack_A, stack_B);
	if (counter == 6)
		check_reverse_shift_B(stack_B);
	if (counter == 7)
		check_reverse_shift_A(stack_A);
	if (counter == 8)
		check_reverse_shift_both(stack_A, stack_B);
	if (counter == 9)
		check_push_a(stack_B, stack_A);
	if (counter == 10)
		check_push_b(stack_A, stack_B);
}

void	implement_moves(t_stack **stack_A, t_stack **stack_B, char *moves)
{
	char	*mv[] = {"sa", "ss", "sb", "ra", "rb", "rr", "rrb", "rra", "rrr",
			   "pa", "pb", 0};
	int		counter;

	counter = 0;
	while (mv[counter] && ft_custom_strcmp(moves, mv[counter]))
		counter++;
	if (counter == 11)
		my_exit(-1);
	else
		func_switcher(stack_A, stack_B, counter);
}

int	checker(int *casher, int counter)
{
	char	*moves;
	t_stack	*stack_A;
	t_stack	*stack_B;

	stack_A = stack_bild(casher, counter);
	if (!stack_A)
		return (0);
	stack_B = 0;
	while (get_next_line(0, &moves))
	{
		implement_moves(&stack_A, &stack_B, moves);
		free(moves);
	}
	free(moves);
	if (sorted_stack(stack_A) && !stack_B)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (stack_A)
		free(stack_A);
	if (stack_B)
		free(stack_B);
	return (1);
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
	if (!checker(cash, counter))
		my_exit(-2);
	return (0);
}
