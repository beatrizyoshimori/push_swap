

#include "push_swap.h"

int	check_if_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_two(t_stack **stack)
{
	if ((*stack)->number > (*stack)->next->number)
		rotate(stack, 'a');
}

void	sort_three(t_stack **stack)
{
	if ((*stack)->number > (*stack)->next->number)
		swap(stack, 'a');
	if ((*stack)->next->number > (*stack)->next->next->number)
		reverse_rotate(stack, 'a');
	if ((*stack)->number > (*stack)->next->number)
		swap(stack, 'a');
}

// void	sort_five(t_stack **stack)
// {
	
// }
