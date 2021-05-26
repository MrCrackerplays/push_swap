#include "push_swap.h"
#include "libft/libft.h"
#include "stdlib.h"
#include "unistd.h"
#include "stdio.h"

char	*magic(t_stacks *stacks)
{
	int	depth;

	depth = stacks->top;
	while (depth < stacks->size - 1)
	{
		if (stacks->a[depth] == stacks->a[depth + 1])
			call_error();
		if (stacks->a[depth] > stacks->a[depth + 1])
		{
			// move_over(stacks, depth);
			// stacks->top = depth; //dit moet wel maar het kan in move_over
			// swap_a();
		}
		depth++;
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_stacks	*stacks;
	char		*commands;

	if (argc < 2)
		call_error();
	stacks = ft_calloc(1, sizeof(t_stacks));
	if (stacks == NULL)
		call_error();
	stacks->a = ft_calloc(argc - 1, sizeof(int *));
	stacks->b = ft_calloc(argc - 1, sizeof(int *));
	if (stacks->a == NULL || stacks->b == NULL)
		call_error();
	parse_args(argc, argv, stacks->a);
	commands = magic(stacks);
	clean_stacks(stacks, argc);
	commands = "sa\n";
	write(1, commands, ft_strlen(commands));
	// free(commands);
}
