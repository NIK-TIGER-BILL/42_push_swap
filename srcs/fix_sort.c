/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:58:43 by ebalsami          #+#    #+#             */
/*   Updated: 2021/05/22 16:58:45 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3_a(t_stack **stack)
{
	if ((*stack)->order > (*stack)->next->order)
		swap_a(stack);
	if ((*stack)->order > (*stack)->previous->order)
		reverse_shift_a(stack);
	if ((*stack)->next->order > (*stack)->previous->order)
	{
		swap_a(stack);
		shift_a(stack);
	}
}

void	sort_3_b(t_stack **stack)
{
	if ((*stack)->order > (*stack)->next->order)
		swap_b(stack);
	if ((*stack)->order > (*stack)->previous->order)
		reverse_shift_b(stack);
	if ((*stack)->next->order > (*stack)->previous->order)
	{
		swap_b(stack);
		shift_b(stack);
	}
}

void	sort_4(t_stack **stack_A, t_stack **stack_B)
{
	while ((*stack_A)->order != 1)
		shift_a(stack_A);
	push_b(stack_A, stack_B);
	sort_3_a(stack_A);
	push_a(stack_B, stack_A);
}

void	sort_5(t_stack **stack_A, t_stack **stack_B)
{
	int	len;

	len = 2;
	while (len)
	{
		if ((*stack_A)->order < 3)
		{
			push_b(stack_A, stack_B);
			len--;
		}
		else
			shift_a(stack_A);
	}
	if ((*stack_B)->order < (*stack_B)->next->order)
		swap_b(stack_B);
	sort_3_a(stack_A);
	while (*stack_B)
		push_a(stack_B, stack_A);
}
