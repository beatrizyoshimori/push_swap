/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:22:15 by byoshimo          #+#    #+#             */
/*   Updated: 2023/03/11 16:46:22 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_last(t_stack *stack)
{
	if (stack == NULL)
		return (stack);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*ft_stack_second_last(t_stack *stack)
{
	if (stack == NULL)
		return (stack);
	while (stack->next->next != NULL)
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
	ft_stack_last(*stack)->next = new;
}

int	stack_size(t_stack *stack)
{
	int		i;

	i = 0;
	while (stack != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

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