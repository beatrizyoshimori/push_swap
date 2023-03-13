

#include "push_swap.h"

void	swap(t_stack **start, char c)
{
	t_stack *tmp;

	if (*start == NULL || (*start)->next == NULL)
		return ;
	tmp = ((*start)->next);
	(*start)->next = (*start)->next->next;
	tmp->next = (*start);
	(*start) = tmp;
	if (c == 'a')
		write(1, "sa\n", 3);
	if (c == 'b')
		write(1, "sb\n", 3);
	if (c == 's')
		write(1, "ss\n", 3);
}

void	rotate(t_stack **start, char c)
{
	t_stack	*tmp_first;

	if (*start == NULL || (*start)->next == NULL)
		return ;
	tmp_first = *start;
	(*start) = (*start)->next;
	ft_stackadd_back(start, tmp_first);
	tmp_first->next = NULL;
	if (c == 'a')
		write(1, "ra\n", 3);
	if (c == 'b')
		write(1, "rb\n", 3);
	if (c == 'r')
		write(1, "rr\n", 3);
}

void	reverse_rotate(t_stack **start, char c)
{
	t_stack	*tmp_last;

	if (*start == NULL || (*start)->next == NULL)
		return ;
	tmp_last = (ft_stack_last(*start));
	ft_stack_second_last(*start)->next = NULL;
	tmp_last->next = *start;
	*start = tmp_last;
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
	if (c == 'r')
		write(1, "rrr\n", 4);
}

void	push(t_stack **src, t_stack **dest, char c)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = (*dest);
	(*dest) = tmp;
	if (c == 'a')
		write(1, "pa\n", 3);
	if (c == 'b')
		write(1, "pb\n", 3);
}
