#include "../includes/push_swap.h"

t_stack	*lstnew(int content, char head, int order)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (0);
	new_node->number = content;
	new_node->head = head;
	new_node->order = order;
	new_node->next = new_node;
	new_node->previous = new_node;
	return (new_node);
}

void	roundlst_addback(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	else if (!*lst)
		*lst = new;
	else
	{
		last = (*lst)->previous;
		new->next = *lst;
		(*lst)->previous = new;
		last->next = new;
		new->previous = last;
	}
}

void	roundlst_addfront(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	else if (!(*lst))
		*lst = new;
	else
	{
		last = (*lst)->previous;
		new->previous = last;
		new->next = *lst;
		last->next = new;
		(*lst)->previous = new;
		(*lst)->head = 0;
		*lst = new;
	}
}

void	roundlst_delfirst(t_stack **stack)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!(*stack))
		return ;
	last = (*stack)->previous;
	if ((*stack)->number == (*stack)->next->number)
	{
		tmp = *stack;
		*stack = 0;
		free(tmp);
	}
	else
	{
		tmp = *stack;
		(*stack) = (*stack)->next;
		(*stack)->previous = last;
		last->next = *stack;
		(*stack)->head = 1;
		free(tmp);
	}
}
