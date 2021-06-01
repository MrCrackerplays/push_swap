#include "push_swap.h"
#include "stddef.h"

void	reverse_rotate_a(t_stack **a)
{
	if (*a == NULL || *a == (*a)->next)
		return ;
	*a = (*a)->previous;
}

void	reverse_rotate_b(t_stack **b)
{
	if (*b == NULL || *b == (*b)->next)
		return ;
	*b = (*b)->previous;
}

void	reverse_rotate_ab(t_stack **a, t_stack **b)
{
	reverse_rotate_a(a);
	reverse_rotate_b(b);
}
