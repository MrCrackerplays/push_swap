#include "push_swap.h"
#include "checker.h"
#include "libft/libft.h"
#include "unistd.h"
#include "get_next_line/get_next_line.h"
#include "stdlib.h"
#include "stdio.h"

void	validate(t_stacks_holder *stacks)
{
	t_stack	*iter;

	if (stacks->b != NULL)
	{
		write(1, "KO\n", 3);
		return ;
	}
	iter = stacks->a;
	while (iter->next != stacks->a)
	{
		if (*(iter->value) >= *(iter->next->value))
		{
			write(1, "KO\n", 3);
			return ;
		}
		iter = iter->next;
	}
	write(1, "OK\n", 3);
}

void	execute(t_stacks_holder *stacks)
{
	static	void	(*action[])(t_stacks_holder *) = {push_a, push_b, swap_a,
		swap_b, swap_ab, rotate_a, rotate_b, rotate_ab, reverse_rotate_a,
		reverse_rotate_b, reverse_rotate_ab};
	int				i;
	char			*str;

	str = NULL;
	i = 1;
	while (i > 0)
	{
		i = get_next_line(1, &str);
		if (i <= 0)
			continue ;
		action[parse_input(str)](stacks);
		free(str);
	}
}

int	main(int argc, char *argv[])
{
	t_stacks_holder	*stacks;

	if (argc < 2)
		return (0);
	stacks = ft_calloc(1, sizeof(t_stacks_holder));
	if (stacks == NULL)
		call_error();
	stacks->a = ft_calloc(1, sizeof(t_stack));
	if (stacks->a == NULL)
		call_error();
	stacks->a->next = stacks->a;
	stacks->a->previous = stacks->a;
	parse_args(argc, argv, stacks);
	execute(stacks);
	validate(stacks);
	clean_stacks(stacks->a, stacks->b);
	free(stacks);
	return (0);
}
