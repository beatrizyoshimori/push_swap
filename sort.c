/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:31:03 by byoshimo          #+#    #+#             */
/*   Updated: 2023/03/17 18:31:06 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	sort_four_and_five(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	size;

	if (check_if_sorted(*stack_a))
		return ;
	i = 0;
	size = stack_size(*stack_a);
	while (i < size)
	{
		if ((*stack_a)->index <= 1)
			push(stack_a, stack_b, 'b');
		else
			rotate(stack_a, 'a');
		i++;
	}
	if (size == 4)
		sort_two(stack_a);
	else
		sort_three(stack_a);
	if ((*stack_b)->index < (*stack_b)->next->index)
		swap(stack_b, 'b');
	while (*stack_b)
		push(stack_b, stack_a, 'a');
}
