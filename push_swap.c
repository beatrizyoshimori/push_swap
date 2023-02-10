/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:05:34 by byoshimo          #+#    #+#             */
/*   Updated: 2023/02/09 21:15:45 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_stack **start)
{
    t_stack tmp;

    tmp = *((*start)->next);
    (*start)->next = (*start)->next->next;
	tmp.next = (*start);
    (*start) = &tmp;
	(*start)->number = tmp.number;
}

void	print_stack(t_stack *start)
{
	t_stack	*stack;

	stack = start;
	while (stack)
	{
		printf("%d\n", stack->number);
		stack = stack->next;
	}
}

void	add_to_stack(t_stack **start, int value)
{
    t_stack *stack;

    stack = (t_stack *)malloc(sizeof(t_stack));
    stack->number = value;
	stack->next = *start;
	*start = stack;
}

int main(int argc, char *argv[])
{
    int     i;
    t_stack *stack;
    //t_stack *head;

    //stack = malloc(sizeof(t_stack));
    //stack->number = ft_atoi(argv[1]);
    //head = stack;
	stack = NULL;
    i = 1;
    while (i < argc)
    {
        add_to_stack(&stack, ft_atoi(argv[i]));
        i++;
    }
	print_stack(stack);
	swap(&stack);
	printf("start->number: %d\n", stack->number);
	print_stack(stack);
    return (0);
}