/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:05:34 by byoshimo          #+#    #+#             */
/*   Updated: 2023/03/17 22:52:49 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	t_stack	*stack_a;
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
	else if (argc >= 5 && argc <= 6)
		sort_four_and_five(&stack_a, &stack_b);
	else if (argc > 6)
		radix(&stack_a, &stack_b);
	clear_stack(&stack_a);
	return (0);
}
