#include "push_swap.h"

void	rotate_a(t_stacks *stacks)
{
	if (stacks->amount < 2)
		return ;
	if (stacks->top_a == stacks->size - stacks->amount)
		stacks->top_a = 0;
	else
		stacks->top_a++;
}

void	rotate_b(t_stacks *stacks)
{
	if (stacks->size - stacks->amount < 2)
		return ;
	if (stacks->top_b == stacks->size - stacks->amount)
		stacks->top_b = 0;
	else
		stacks->top_b++;
}

void	rotate_ab(t_stacks *stacks)
{
	rotate_a(stacks);
	rotate_b(stacks);
}
