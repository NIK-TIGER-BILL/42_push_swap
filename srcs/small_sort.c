#include "../includes/push_swap.h"

int	find_next_min(t_stack *stack, int min)
{
	int		forward;
	int		back;
	t_stack	*tmp;

	tmp = stack;
	forward = 0;
	back = 0;
	while (stack->order != min)
	{
		stack = stack->next;
		forward++;
	}
	while (tmp->order != min)
	{
		tmp = tmp->previous;
		back++;
	}
	return (forward < back);
}

void	find_way(t_stack **stack_A, t_stack **stack_B, int min)
{
	if (find_next_min(*stack_A, min))
	{
		while ((*stack_A)->order != min)
			shift_A(stack_A);
	}
	else
	{
		while ((*stack_A)->order != min)
			reverse_shift_A(stack_A);
	}
	push_b(stack_A, stack_B);
}

void	small_sort(t_stack **stack_A, t_stack **stack_B)
{
	int	min;
	int	max;

	min = 1;
	max = len_stack(*stack_A);
	while (min < max - 1)
	{
		find_way(stack_A, stack_B, min);
		min++;
	}
	if ((*stack_A)->order > (*stack_A)->next->order)
		swap_a(stack_A);
	while (*stack_B)
		push_a(stack_B, stack_A);
}
