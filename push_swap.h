/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:05:40 by byoshimo          #+#    #+#             */
/*   Updated: 2023/03/04 17:17:47 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#include "libft/libft.h"

typedef struct s_stack
{
	int				number;
	int				index;
	int				position;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_stack_last(t_stack *stack);
t_stack	*ft_stack_second_last(t_stack *stack);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	add_to_stack(t_stack **start, int value);
void    swap(t_stack **start);
void	rotate(t_stack **start);
void	reverse_rotate(t_stack **start);
void	push(t_stack **src, t_stack **dest);
void    radix(t_stack *stack_a, t_stack *stack_b);

#endif