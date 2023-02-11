/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:05:40 by byoshimo          #+#    #+#             */
/*   Updated: 2023/02/10 21:24:53 by byoshimo         ###   ########.fr       */
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

void	add_to_stack(t_stack **start, int value);
void	print_stack(t_stack *start);
t_stack	*ft_stacklast(t_stack *stack);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	add_to_stack(t_stack **start, int value);

#endif