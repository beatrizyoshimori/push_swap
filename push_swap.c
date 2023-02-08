
#include "push_swap.h"

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
    return (0);
}