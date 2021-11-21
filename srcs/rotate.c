#include "../includes/push_swap.h"

void    shift(t_stack **stack)
{
    if (len_stack(*stack) > 1) //todo затратно, нам нужно знать что больше одного элемента, но нам не нужна информация о всем кол-во элементов. len_stack занимает O(n)
    {
        (*stack)->next->head = 1;
        (*stack)->head = 0;
        (*stack) = (*stack)->next;
    }
}

void	shift_A(t_stack **stack)
{
    shift(stack);
	write(1, "ra\n", 3); //todo hardcoding
}

void	shift_B(t_stack **stack)
{
    shift(stack);
	write(1, "rb\n", 3); //todo hardcoding
}

void	shift_both(t_stack **stack_A, t_stack **stack_B) // todo объеденить функциаонал 3 (3 строка, 14 строка, 25 строка) функций в 1. Метод DRY не повторяйся!
{
    shift(stack_A);
    shift(stack_B);
	write(1, "rr\n", 3); //todo hardcoding
}
