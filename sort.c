

#include "push_swap.h"


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
