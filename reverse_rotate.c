#include "push_swap.h"

void	reverse_rotate_a(t_stacks *stacks)
{
	if (stacks->top_a == stacks->size - stacks->amount)
		stacks->top_a = 0;
	else
		stacks->top_a++;
}

void	reverse_rotate_b(t_stacks *stacks)
{
	if (stacks->top_b == stacks->size - stacks->amount)
		stacks->top_b = 0;
	else
		stacks->top_b++;
}

void	reverse_rotate_ab(t_stacks *stacks)
{
	reverse_rotate_a(stacks);
	reverse_rotate_b(stacks);
}
