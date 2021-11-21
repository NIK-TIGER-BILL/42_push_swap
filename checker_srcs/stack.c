#include "../includes/push_swap.h"

t_stack	*stack_constructor(int *cash, int counter)
{
	int				index;
	t_stack			*stack_A;

	index = 0;
	stack_A = lstnew(cash[index], 1, 0);
	while (++index < counter)
		roundlst_addback(&stack_A, lstnew(cash[index], 0, 0));
	return (stack_A);
}


