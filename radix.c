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

void	sort_radix(t_stack **stack_a, t_stack **stack_b, int i)
{
	int	size;

	size = stack_size(*stack_a);
	while (size > 0)
	{
		if (((*stack_a)->number >> i & 1) == 0)
			push(stack_a, stack_b, 'b');
		else
			rotate(stack_a, 'a');
		size--;
	}
	while (*stack_b)
		push(stack_b, stack_a, 'a');
}

void    radix(t_stack **stack_a, t_stack **stack_b)
{
    int i;

    i = 0;
    while (i < 8 && !check_if_sorted(*stack_a))
    {
		sort_radix(stack_a, stack_b, i);
		i++;
    }
}