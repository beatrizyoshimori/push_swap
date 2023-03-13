

#include "push_swap.h"

void	add_to_stack(t_stack **start, int value)
{
    t_stack *new;

    new = (t_stack *)malloc(sizeof(t_stack));
    new->number = value;
    new->next = NULL;
    ft_stackadd_back(start, new);
}

void	get_index(t_stack *stack)
{
	t_stack	*beg_stack;
	t_stack *tmp;

	beg_stack = stack;
	while (stack)
	{
		stack->index = 0;
		tmp = beg_stack;
		while (tmp)
		{
			if (stack->number > tmp->number)
				(stack->index)++;
			tmp = tmp->next;
		}
		stack = stack->next;
	}
}