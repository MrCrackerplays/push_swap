#include "push_swap.h"
#include "stddef.h"

void	swap_a(t_stack **a)
{
	t_stack	*original;

	if (*a == NULL || *a == (*a)->next)
		return ;
	original = *a;
	*a = original->next;
	original->next = (*a)->next;
	(*a)->previous = original->previous;
	original->previous = *a;
	(*a)->next = original;
	(*a)->previous->next = *a;
	original->next->previous = original;
}

void	swap_b(t_stack **b)
{
	t_stack	*original;

	if (*b == NULL || *b == (*b)->next)
		return ;
	original = *b;
	*b = original->next;
	original->next = (*b)->next;
	(*b)->previous = original->previous;
	original->previous = *b;
	(*b)->next = original;
	(*b)->previous->next = *b;
	original->next->previous = original;
}

void	swap_ab(t_stack **a, t_stack **b)
{
	swap_a(a);
	swap_b(b);
}
