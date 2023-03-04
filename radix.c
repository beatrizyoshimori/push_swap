/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:32:04 by byoshimo          #+#    #+#             */
/*   Updated: 2023/03/04 18:09:44 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a(t_stack **stack_a, t_stack **stack_b, int i)
{
	while (*stack_a)
	{
		if (((*stack_a)->number >> i & 1) == 0)
			push(stack_a, stack_b);
		else
			rotate(stack_a);
		*stack_a = (*stack_a)->next;
	}
}

void	sort_b(t_stack **stack_a, t_stack **stack_b)
{
	while (stack_b)
	{
		push(stack_b, stack_a);
		*stack_b = (*stack_b)->next;
	}
}

void    radix(t_stack *stack_a, t_stack *stack_b)
{
    int i;
    // t_stack *tmp;

    i = 0;
    while (i < 8)
    {
		sort_a(&stack_a, &stack_b, i);
		sort_b(&stack_a, &stack_b);
		i++;
    }
}