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

void	check_arg(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if(argv[i][j] < '0' || argv[i][j] > '9')
			{
				write(1, "Error\n", 6);
				exit(1);
			}
		}
	}
	i = 0;
	while (++i < argc)
	{
		j = i;
		while (++j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				write(1, "Error\n", 6);
				exit(1);
			}
		}
	}
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

// void	sort_five(t_stack **stack)
// {
	
// }

int main(int argc, char *argv[])
{
    int     i;
    t_stack *stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	check_arg(argc, argv);
    i = 1;
    while (i < argc)
	{
        add_to_stack(&stack_a, ft_atoi(argv[i++]));
	}
	if (argc == 3)
		sort_two(&stack_a);
	else if (argc == 4)
		sort_three(&stack_a);
	else
		radix(&stack_a, &stack_b);
	// printf("aqui\n");
	// print_stack(stack_a);
	//printf("\nb:\n");
	//print_stack(stack_b);
    return (0);
}