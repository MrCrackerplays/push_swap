#include "push_swap.h"
#include "libft/libft.h"
#include "stdlib.h"
#include "unistd.h"



char	*magic(t_stacks_holder *stacks)
{
	char	*str;
	char	*temp;

	str = malloc(sizeof(char));
	if (str == NULL)
		call_error();
	*str = '\0';
	while (stacks->a != NULL)
	{
		;
	}
	while (stacks->b != NULL)
	{
		push_a(stacks);
		temp = ft_strjoin(str, "pa\n");
		if (temp == NULL)
			call_error();
		free(str);
		str = temp;
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_stacks_holder	*stacks;
	char			*commands;

	if (argc < 2)
		call_error();
	stacks = ft_calloc(1, sizeof(t_stacks_holder));
	if (stacks == NULL)
		call_error();
	stacks->a = ft_calloc(1, sizeof(t_stack));
	if (stacks->a == NULL)
		call_error();
	stacks->a->next = stacks->a;
	stacks->a->previous = stacks->a;
	parse_args(argc, argv, stacks->a);
	commands = magic(stacks);
	clean_stacks(stacks, argc);
	commands = "sa\n";
	write(1, commands, ft_strlen(commands));
	// free(commands);
}
