#include "push_swap.h"
#include "stddef.h"

void	push_a(t_stacks_holder *stacks)
{
	if (stacks->size - stacks->amount == 0)
		return ;
	if (stacks->amount != stacks->size)
	{
		if (stacks->top_a == 0)
			stacks->top_a = stacks->size;
		else
			stacks->top_a = (stacks->top_b - 1);
	}
	stacks->a[stacks->top_a] = stacks->b[stacks->top_b];
	stacks->b[stacks->top_b] = NULL;
	stacks->top_b = (stacks->top_b + 1) % stacks->size;
	stacks->amount++;
}

void	push_b(t_stacks_holder *stacks)
{
	if (stacks->amount == 0)
		return ;
	if ((stacks->size - stacks->amount) != stacks->size)
	{
		if (stacks->top_b == 0)
			stacks->top_b = stacks->size;
		else
			stacks->top_b = (stacks->top_a - 1);
	}
	stacks->b[stacks->top_b] = stacks->a[stacks->top_a];
	stacks->a[stacks->top_a] = NULL;
	stacks->top_a = (stacks->top_a + 1) % stacks->size;
	stacks->amount--;
}
