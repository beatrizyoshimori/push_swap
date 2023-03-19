/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:05:40 by byoshimo          #+#    #+#             */
/*   Updated: 2023/03/17 22:59:37 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_stack_last(t_stack *stack);
t_stack	*ft_stack_second_last(t_stack *stack);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
int		stack_size(t_stack *stack);
void	clear_stack(t_stack **stack);
void	swap(t_stack **start, char c);
void	rotate(t_stack **start, char c);
void	reverse_rotate(t_stack **start, char c);
void	push(t_stack **src, t_stack **dest, char c);
void	swap_both(t_stack **stack_a, t_stack **stack_b);
void	rotate_both(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);
void	radix(t_stack **stack_a, t_stack **stack_b);
void	check_arg(int argc, char *argv[]);
void	add_to_stack(t_stack **start, int value);
void	get_index(t_stack *stack);
int		check_if_sorted(t_stack *stack);
void	sort_two(t_stack **stack);
void	sort_three(t_stack **stack);
void	sort_four_and_five(t_stack **stack_a, t_stack **stack_b);

#endif