#include "push_swap.h"

void	swap_a(t_stacks *stacks)
{
	int	*top;

	if (stacks->amount < 2)
		return ;
	top = (stacks->a)[stacks->top_a];
	(stacks->a)[stacks->top_a] = (stacks->a)[(stacks->top_a + 1)
		% stacks->amount];
	(stacks->a)[(stacks->top_a + 1) % stacks->amount] = top;
}

void	swap_b(t_stacks *stacks)
{
	int	*top;

	if (stacks->size - stacks->amount < 2)
		return ;
	top = (stacks->b)[0];
	(stacks->b)[stacks->top_b] = (stacks->b)[(stacks->top_b + 1)
		% (stacks->size - stacks->amount)];
	(stacks->b)[(stacks->top_b + 1) % (stacks->size - stacks->amount)] = top;
}

void	swap_ab(t_stacks *stacks)
{
	swap_a(stacks);
	swap_b(stacks);
}
