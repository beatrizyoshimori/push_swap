

#include "push_swap.h"

void    swap(t_stack **start)
{
    t_stack *tmp;

	if (*start == NULL || (*start)->next == NULL)
		return ;
    tmp = ((*start)->next);
    (*start)->next = (*start)->next->next;
	tmp->next = (*start);
    (*start) = tmp;
}

void	rotate(t_stack **start)
{
	t_stack	*tmp_first;

	if (*start == NULL || (*start)->next == NULL)
		return ;
	tmp_first = *start;
	(*start) = (*start)->next;
	ft_stackadd_back(start, tmp_first);
	tmp_first->next = NULL;
}

void	reverse_rotate(t_stack **start)
{
	t_stack	*tmp_last;

	if (*start == NULL || (*start)->next == NULL)
		return ;
	tmp_last = (ft_stack_last(*start));
	ft_stack_second_last(*start)->next = NULL;
	tmp_last->next = *start;
	*start = tmp_last;
}

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = (*dest);
	(*dest) = tmp;
}
