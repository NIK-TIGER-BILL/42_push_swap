#include "../includes/push_swap.h"

void check_push_b(t_stack **stack_A, t_stack **stack_B)
{
	if (*stack_A)
	{
		roundlst_addfront(stack_B, lstnew((*stack_A)->number, 1, (*stack_A)->order));
		roundlst_delfirst(stack_A);
	}
}

void check_push_a(t_stack **stack_B, t_stack **stack_A)
{
	if (*stack_B)
	{
		roundlst_addfront(stack_A, lstnew((*stack_B)->number, 1, (*stack_B)->order));
		roundlst_delfirst(stack_B);
	}
}
