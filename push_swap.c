/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:05:34 by byoshimo          #+#    #+#             */
/*   Updated: 2023/03/11 20:00:19 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d\n", stack->number);
		stack = stack->next;
	}
}

int main(int argc, char *argv[])
{
	int		i;
	t_stack *stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	check_arg(argc, argv);
	i = 1;
	while (i < argc)
		add_to_stack(&stack_a, ft_atoi(argv[i++]));
	get_index(stack_a);
	if (argc == 3)
		sort_two(&stack_a);
	else if (argc == 4)
		sort_three(&stack_a);
	else
		radix(&stack_a, &stack_b);
	// print_stack(stack_a);
	//printf("\nb:\n");
	//print_stack(stack_b);
	return (0);
}