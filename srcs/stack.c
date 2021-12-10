/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:58:43 by ebalsami          #+#    #+#             */
/*   Updated: 2021/05/22 16:58:45 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*stack_constructor(int *cash, int counter)
{
	int				index;
	t_stack			*stack_a;

	index = 0;
	stack_a = lstnew(cash[index], 1, 0);
	if (!stack_a)
		return (0);
	while (++index < counter)
		roundlst_addback(&stack_a, lstnew(cash[index], 0, 0));
	return (stack_a);
}

void	pre_sorting(t_stack **stack_A, int *cash, int counter)
{
	int			index;
	int			order;
	int			n;

	index = 0;
	while (index < counter)
	{
		order = 0;
		n = 0;
		while (n < counter)
		{
			if (cash[index] > cash[n])
				order++;
			n++;
		}
		(*stack_A)->order = order + 1;
		(*stack_A) = (*stack_A)->next;
		index++;
	}
}

void	little_sort(t_stack **stack_A, t_stack **stack_B)
{
	if (len_stack(*stack_A) == 3)
		sort_3_a(stack_A);
	else if (len_stack(*stack_A) == 4)
		sort_4(stack_A, stack_B);
	else if (len_stack(*stack_A) == 5)
		sort_5(stack_A, stack_B);
	else
		small_sort(stack_A, stack_B);
}

void	stack_init(int *cash, int counter)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_b = 0;
	stack_a = stack_constructor(cash, counter);
	if (!stack_a)
	{
		free(cash);
		my_exit(-2);
	}
	if (!sorted_stack(stack_a))
	{
		pre_sorting(&stack_a, cash, counter);
		free(cash);
		if (len_stack(stack_a) <= 31)
			little_sort(&stack_a, &stack_b);
		else
			sort(&stack_a, &stack_b);
	}
	if (stack_a)
		free_stack(&stack_a);
	if (stack_b)
		free_stack(&stack_b);
}
