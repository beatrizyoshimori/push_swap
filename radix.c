/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:32:04 by byoshimo          #+#    #+#             */
/*   Updated: 2023/03/11 16:43:20 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bit(t_stack *stack)
{
	int	max_index;
	int	max_bit;

	max_index = stack->index;
	stack = stack->next;
	while (stack)
	{
		if (stack->index > max_index)
			max_index = stack->index;
		stack = stack->next;
	}
	max_bit = 0;
	while ((max_index | 0) != 0)
	{
		max_bit++;
		max_index = max_index >> 1;
	}
	return (max_bit);
}

void	sort_radix(t_stack **stack_a, t_stack **stack_b, int i)
{
	int	size;

	size = stack_size(*stack_a);
	while (size > 0)
	{
		if (((*stack_a)->index >> i & 1) == 0)
			push(stack_a, stack_b, 'b');
		else
			rotate(stack_a, 'a');
		size--;
	}
	while (*stack_b)
		push(stack_b, stack_a, 'a');
}

void	radix(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int max_bit;

	i = 0;
	max_bit = get_max_bit(*stack_a);
	while (i < max_bit && !check_if_sorted(*stack_a))
	{
		sort_radix(stack_a, stack_b, i);
		i++;
	}
}