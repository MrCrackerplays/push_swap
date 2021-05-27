#include "push_swap.h"

void	swap_a(t_stacks *stacks)
{
	int	*top;

	top = (stacks->a)[0];
	(stacks->a)[0] = (stacks->a)[1];
	(stacks->a)[1] = top;
}

void	swap_b(t_stacks *stacks)
{
	int	*top;

	top = (stacks->b)[0];
	(stacks->b)[0] = (stacks->b)[1];
	(stacks->b)[1] = top;
}

void	swap_ab(t_stacks *stacks)
{
	swap_a(stacks);
	swap_b(stacks);
}
