/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:58:43 by ebalsami          #+#    #+#             */
/*   Updated: 2021/05/22 16:58:45 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*stack_bild(int *cash, int counter)
{
	t_stack		*stack_a;

	stack_a = stack_constructor(cash, counter);
	free(cash);
	return (stack_a);
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
		check_shift_a(stack_A);
	if (counter == 4)
		check_shift_b(stack_B);
	if (counter == 5)
		check_shift_both(stack_A, stack_B);
	if (counter == 6)
		check_reverse_shift_b(stack_B);
	if (counter == 7)
		check_reverse_shift_a(stack_A);
	if (counter == 8)
		check_reverse_shift_both(stack_A, stack_B);
	if (counter == 9)
		check_push_a(stack_B, stack_A);
	if (counter == 10)
		check_push_b(stack_A, stack_B);
}

void	implement_moves(t_stack **stack_A, t_stack **stack_B, char *moves)
{
	char	*mv[12];
	int		counter;

	mv[0] = "sa";
	mv[1] = "ss";
	mv[2] = "sb";
	mv[3] = "ra";
	mv[4] = "rb";
	mv[5] = "rr";
	mv[6] = "rrb";
	mv[7] = "rra";
	mv[8] = "rrr";
	mv[9] = "pa";
	mv[10] = "pb";
	mv[11] = 0;
	counter = 0;
	while (mv[counter] && !ft_custom_strcmp(moves, mv[counter]))
		counter++;
	if (counter == 11)
		my_exit(-1);
	else
		func_switcher(stack_A, stack_B, counter);
}

int	checker(int *casher, int counter)
{
	char	*moves;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = stack_bild(casher, counter);
	if (!stack_a)
		return (0);
	stack_b = 0;
	while (get_next_line(0, &moves))
	{
		implement_moves(&stack_a, &stack_b, moves);
		free(moves);
	}
	free(moves);
	if (sorted_stack(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (stack_a)
		free_stack(&stack_a);
	if (stack_b)
		free_stack(&stack_b);
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
	if (counter == -1)
	{
		free(cash);
		my_exit(-2);
	}
	if (!checker(cash, counter))
		my_exit(-2);
	return (0);
}
