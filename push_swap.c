#include "push_swap.h"
#include "libft/libft.h"
#include "stdlib.h"
#include "unistd.h"

void	move_up_stack(int **a, int **b, int depth, int size)
{
	;
}

char	*magic(int **a, int **b, int size)
{
	int	depth;

	depth = 0;
	while (depth < size - 1)
	{
		if (a[depth] < a[depth + 1])
			;//swep
		depth++;
	}
	if (a || b)
		;
	return (NULL);
}

int	main(int argc, char *argv[])
{
	int		**a;
	int		**b;
	int		i;
	char	*commands;

	if (argc < 2)
		call_error();
	a = ft_calloc(argc - 1, sizeof(int *));
	b = ft_calloc(argc - 1, sizeof(int *));
	parse_args(argc, argv, a);
	commands = magic(a, b, argc - 1);
	i = 0;
	while (i < argc - 1)
	{
		free(a[i]);
		i++;
	}
	free(a);
	free(b);
	// write(1, commands, ft_strlen(commands));
}
