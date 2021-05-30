#include "push_swap.h"

void	reverse_rotate_a(t_stacks *stacks)
{
	if (stacks->amount < 2)
		return ;
	if (stacks->top_a + stacks->amount < stacks->size)
		stacks->top_a = (stacks->top_a + stacks->amount - 1) % stacks->size;
	else
		stacks->top_a = stacks->top_a + stacks->amount - 1;
	// if (stacks->top_a == 0)
	// 	stacks->top_a = stacks->amount - 1;
	// else
	// 	stacks->top_a--;
}

void	reverse_rotate_b(t_stacks *stacks)
{
	if (stacks->size - stacks->amount < 2)
		return ;
	if (stacks->top_b == 0)
		stacks->top_b = stacks->size - stacks->amount - 1;
	else
		stacks->top_b--;
}

void	reverse_rotate_ab(t_stacks *stacks)
{
	reverse_rotate_a(stacks);
	reverse_rotate_b(stacks);
}
