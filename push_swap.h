

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#include "libft/libft.h"

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
}	t_stack;

#endif