/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:05:40 by byoshimo          #+#    #+#             */
/*   Updated: 2023/02/08 21:07:08 by byoshimo         ###   ########.fr       */
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
#endif