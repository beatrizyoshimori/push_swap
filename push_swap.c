/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:05:34 by byoshimo          #+#    #+#             */
/*   Updated: 2023/02/10 21:54:03 by byoshimo         ###   ########.fr       */
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

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d\n", stack->number);
		stack = stack->next;
	}
}

void	rotate(t_stack **start)
{
	t_stack	tmp_first;
	t_stack	tmp_last;

	tmp_first = **start;
	tmp_first.next = NULL;
	tmp_last = (*ft_stacklast(*start));
	tmp_last.next = (*start)->next;
	(*start) = &tmp_last;
	*(ft_stacklast(*start)) = tmp_first;
}

int main(int argc, char *argv[])
{
    int     i;
    t_stack *stack;

	stack = NULL;
    i = 1;
    while (i < argc)
    {
        add_to_stack(&stack, ft_atoi(argv[i]));
        i++;
    }
	print_stack(stack);
	//swap(&stack);
	rotate(&stack);
	//printf("start->number: %d\n", stack->number);
	print_stack(stack);
    return (0);
}