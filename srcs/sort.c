#include "../includes/push_swap.h"

int	sorted_stack(t_stack *stack)
{
	int	last;

	last = stack->previous->number;
	while (stack->number != last)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	push_chunks(t_stack **stack_A, t_stack **stack_B, t_medians *chunks)
{
	while (*stack_A)
	{
		if ((*stack_A)->order <= chunks->num)
		{
			push_b(stack_A, stack_B);
			shift_B(stack_B);
			chunks->num++;
		}
		else if ((*stack_A)->order <= chunks->num + chunks->step)
		{
			push_b(stack_A, stack_B);
			chunks->num++;
		}
		else
			shift_A(stack_A);
	}
}

int	find_next(t_stack *stack_B, t_medians *chunks)
{
	int		forward;
	int		back;
	t_stack	*tmp;

	tmp = stack_B;
	forward = 0;
	back = 0;
	while (stack_B->order != chunks->num)
	{
		stack_B = stack_B->next;
		forward++;
	}
	while (tmp->order != chunks->num)
	{
		tmp = tmp->previous;
		back++;
	}
	return (forward < back);
}

void	sorting_back(t_stack **stack_A, t_stack **stack_B, t_medians *chunks)
{
	while ((*stack_B))
	{
		if ((*stack_B)->order == chunks->num)
		{
			push_a(stack_B, stack_A);
			chunks->num--;
		}
		else if (find_next(*stack_B, chunks))
			shift_B(stack_B);
		else
			reverse_shift_B(stack_B);
	}
}

void	sort(t_stack **stack_A, t_stack **stack_B)
{
	t_medians	*chunks;

	chunks = malloc(sizeof(chunks));
	if (!chunks)
		exit(0);
	chunks->num = 0;
	chunks->step = 15;
	if (len_stack(*stack_A) > 250)
		chunks->step += 15;
	push_chunks(stack_A, stack_B, chunks);
	sorting_back(stack_A, stack_B, chunks);
}
