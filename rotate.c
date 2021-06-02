#include "push_swap.h"
#include "stddef.h"

void	rotate_a(t_stacks_holder *stacks)
{
	if (stacks->a == NULL || stacks->a == stacks->a->next)
		return ;
	stacks->a = stacks->a->next;
}

void	rotate_b(t_stacks_holder *stacks)
{
	if (stacks->b == NULL || stacks->b == stacks->b->next)
		return ;
	stacks->b = stacks->b->next;
}

void	rotate_ab(t_stacks_holder *stacks)
{
	rotate_a(stacks);
	rotate_b(stacks);
}
