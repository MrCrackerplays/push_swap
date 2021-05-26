#include "push_swap.h"
#include "libft/libft.h"
#include "unistd.h"
#include "get_next_line/get_next_line.h"
#include "stdlib.h"
#include "stdio.h"

// int	main(int argc, char *argv[])
// {
// 	t_stacks	*stacks;
// 	char		*commands;

// 	if (argc < 2)
// 		call_error();
// 	commands = magic(stacks);
// 	clean_stacks(stacks, argc);
// 	commands = "sa\n";
// 	write(1, commands, ft_strlen(commands));
// 	// free(commands);
// }

void	validate(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->size - 1)
	{
		if (*stacks->a[i] > *stacks->a[i + 1])
		{
			write(1, "KO\n", 3);
			return ;
		}
		i++;
	}
	write(1, "OK\n", 3);
}

void	execute(t_stacks *stacks)
{
	int		i;
	char	*str;

	str = NULL;
	i = 1;
	while (i > 0)
	{
		i = get_next_line(1, &str);
		printf("<>>%i:%ss\n", i, str);
		free(str);
	}
	if (stacks)
		;
}

int	main(int argc, char *argv[])
{
	t_stacks	*stacks;

	if (argc < 2)
		return (0);
	stacks = ft_calloc(1, sizeof(t_stacks));
	if (stacks == NULL)
		call_error();
	stacks->a = ft_calloc(argc - 1, sizeof(int *));
	stacks->b = ft_calloc(argc - 1, sizeof(int *));
	if (stacks->a == NULL || stacks->b == NULL)
		call_error();
	stacks->size = argc - 1;
	stacks->top = 0;
	parse_args(argc, argv, stacks->a);
	execute(stacks);
	validate(stacks);
	clean_stacks(stacks, argc);
	return (0);
}
