#include "push_swap.h"
#include "checker.h"
#include "libft/libft.h"
#include "unistd.h"
#include "get_next_line/get_next_line.h"
#include "stdlib.h"

void	validate(t_stacks *stacks)
{
	unsigned int	i;

	if (stacks->amount < stacks->size)
	{
		write(1, "KO\n", 3);
		return ;
	}
	i = stacks->top_a;
	while (i < stacks->size - 1)
	{
		if (*stacks->a[i % stacks->size] > *stacks->a[(i + 1) % stacks->size])
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
	static	void	(*action[])(t_stacks *) = {push_a, push_b, swap_a, swap_b,
		swap_ab, rotate_a, rotate_b, rotate_ab, reverse_rotate_a,
		reverse_rotate_b, reverse_rotate_ab};
	int				i;
	char			*str;
	char			c[4];

	c[0] = 'a';
	c[1] = '\0';
	c[2] = '\0';
	c[3] = '\0';
	str = &(c[0]);
	i = 1;
	while (i > 0)
	{
		i = get_next_line(1, &str);
		if (i > 0)
			action[parse_input(str)](stacks);
		free(str);
	}
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
	stacks->amount = stacks->size;
	stacks->top_a = 0;
	stacks->top_b = 0;
	parse_args(argc, argv, stacks->a);
	execute(stacks);
	validate(stacks);
	clean_stacks(stacks, argc);
	return (0);
}
