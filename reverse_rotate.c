#include "universal_stacks.h"
#include "stddef.h"

void	reverse_rotate_a(t_stacks_holder *stacks)
{
	if (stacks->a == NULL || stacks->a == stacks->a->next)
		return ;
	stacks->a = stacks->a->previous;
}

void	reverse_rotate_b(t_stacks_holder *stacks)
{
	if (stacks->b == NULL || stacks->b == stacks->b->next)
		return ;
	stacks->b = stacks->b->previous;
}

void	reverse_rotate_ab(t_stacks_holder *stacks)
{
	reverse_rotate_a(stacks);
	reverse_rotate_b(stacks);
}
