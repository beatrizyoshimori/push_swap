/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:22:15 by byoshimo          #+#    #+#             */
/*   Updated: 2023/02/10 21:24:49 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacklast(t_stack *stack)
{
	if (stack == NULL)
		return (stack);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	ft_stacklast(*stack)->next = new;
}

void	add_to_stack(t_stack **start, int value)
{
    t_stack *new;

    new = (t_stack *)malloc(sizeof(t_stack));
    new->number = value;
    new->next = NULL;
    ft_stackadd_back(start, new);
}
