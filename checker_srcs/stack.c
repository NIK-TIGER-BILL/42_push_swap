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
	while (++index < counter)
		roundlst_addback(&stack_a, lstnew(cash[index], 0, 0));
	return (stack_a);
}
