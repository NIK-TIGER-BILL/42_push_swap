#include "../includes/push_swap.h"

t_stack	*stack_constructor(int *cash, int counter)
{
	int				index;
	t_stack			*stack_A;

	index = 0;
	stack_A = lstnew(cash[index], 1, 0);
	if (!stack_A)
		return (0);
	while (++index < counter)
		roundlst_addback(&stack_A, lstnew(cash[index], 0, 0));
	return (stack_A);
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
	t_stack		*stack_A;
	t_stack		*stack_B;

	stack_B = 0;
	stack_A = stack_constructor(cash, counter);
	if (!stack_A)
	{
		free(cash);
		my_exit(-2);
	}
	if (!sorted_stack(stack_A))
	{
		pre_sorting(&stack_A, cash, counter);
		free(cash);
		if (len_stack(stack_A) <= 31)
			little_sort(&stack_A, &stack_B);
		else
			sort(&stack_A, &stack_B);
	}
	if (stack_A)
		free_stack(&stack_A);
	if (stack_B)
		free_stack(&stack_B);
}
