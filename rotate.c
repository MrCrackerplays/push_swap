#include "push_swap.h"

void	rotate_a(t_stacks *stacks)
{
	if (stacks->top_a == 0)
		stacks->top_a = stacks->size - stacks->amount;
	else
		stacks->top_a--;
}

void	rotate_b(t_stacks *stacks)
{
	if (stacks->top_b == 0)
		stacks->top_b = stacks->size - stacks->amount;
	else
		stacks->top_b--;
}

void	rotate_ab(t_stacks *stacks)
{
	rotate_a(stacks);
	rotate_b(stacks);
}
