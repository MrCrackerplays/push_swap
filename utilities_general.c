#include "universal_stacks.h"
#include "libft/libft.h"
#include "stdlib.h"
#include "unistd.h"

void	call_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	clean_stacks(t_stack *a, t_stack *b)
{
	t_stack	*iter;

	if (a)
	{
		iter = a->next;
		while (iter != a)
		{
			iter = iter->next;
			free(iter->previous);
		}
		free(a);
	}
	if (b)
	{
		iter = b->next;
		while (iter != b)
		{
			iter = iter->next;
			free(iter->previous);
		}
		free(b);
	}
}
