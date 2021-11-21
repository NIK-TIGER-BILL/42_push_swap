#include "../includes/push_swap.h"

void	check_swap_a(t_stack **stack_a)
{
	int number;
	int order;

	if ((*stack_a) && (*stack_a)->next)
	{
		number = (*stack_a)->next->number;
		order = (*stack_a)->next->order;
		(*stack_a)->next->number = (*stack_a)->number;
		(*stack_a)->next->order = (*stack_a)->order;
		(*stack_a)->number = number;
		(*stack_a)->order = order;
	}
}
void	check_swap_b(t_stack **stack_b)
{
	int number;
	int order;

	if ((*stack_b) && (*stack_b)->next)
	{
		number = (*stack_b)->next->number;
		order = (*stack_b)->next->order;
		(*stack_b)->next->number = (*stack_b)->number;
		(*stack_b)->next->order = (*stack_b)->order;
		(*stack_b)->number = number;
		(*stack_b)->order = order;
	}
}

void	check_swap_both(t_stack **stack_a, t_stack **stack_b)
{
	int number;
	int order;

	if ((*stack_b) && (*stack_b)->next)
	{
		number = (*stack_b)->next->number;
		order = (*stack_b)->next->order;
		(*stack_b)->next->number = (*stack_b)->number;
		(*stack_b)->next->order = (*stack_b)->order;
		(*stack_b)->number = number;
		(*stack_b)->order = order;
	}
	if ((*stack_a) && (*stack_a)->next)
	{
		number = (*stack_a)->next->number;
		order = (*stack_a)->next->order;
		(*stack_a)->next->number = (*stack_a)->number;
		(*stack_a)->next->order = (*stack_a)->order;
		(*stack_a)->number = number;
		(*stack_a)->order = order;
	}
}