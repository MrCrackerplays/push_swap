#include "push_swap.h"
#include "stddef.h"

void	rotate_a(t_stack **a)
{
	if (*a == NULL || *a == (*a)->next)
		return ;
	*a = (*a)->next;
}

void	rotate_b(t_stack **b)
{
	if (*b == NULL || *b == (*b)->next)
		return ;
	*b = (*b)->next;
}

void	rotate_ab(t_stack **a, t_stack **b)
{
	rotate_a(a);
	rotate_b(b);
}
