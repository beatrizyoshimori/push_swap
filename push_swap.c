
#include "push_swap.h"

t_stack    *add_to_stack(int value)
{
    t_stack *stack;

    stack = malloc(sizeof(t_stack));
    stack->number = value;
    return (stack);
}

int main(int argc, char *argv[])
{
    int     i;
    t_stack *stack;

    i = 1;
    while (i < argc)
    {
        stack = add_to_stack(ft_atoi(argv[i]));
        printf("%d\n", stack->number);
        stack = stack->next;
        i++;
    }
    return (0);
}