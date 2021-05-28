#include "push_swap.h"
#include "libft/libft.h"
#include "unistd.h"
#include "get_next_line/get_next_line.h"
#include "stdlib.h"
#include "stdio.h"

void	validate(t_stacks *stacks)
{
	unsigned int	i;

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
	static	void	(*action[])(t_stacks *) = {push_a, push_b, swap_a, swap_b,
		swap_ab, rotate_a, rotate_ab, rotate_b, reverse_rotate_a,
		reverse_rotate_b, reverse_rotate_ab};
	int				i;
	char			*str;
	char			c[2];
	int				element;

	c[0] = 'a';
	c[1] = '\0';
	str = &(c[0]);
	i = 1;
	element = -1;
	while (i > 0)
	{
		i = get_next_line(1, &str);
		// if (str[0] == 'p')
		// 	element = (str[1] == 'a') + (2 * (str[1] == 'b') + (-5 * str[2] != '\n'));
		// if (str[0] == 's')
		element = (int)0b11111111111111111111111111111111;
		//push
		element = 0b0000;
		element = 0b0001;
		//swap
		// element = 0b0010;
		// element = 0b0011;
		// element = 0b0100;
		// //rotate
		// element = 0b0101;
		// element = 0b0111;
		// element = 0b1000;
		// //reverse rotate
		// element = 0b1001;
		// element = 0b1010;
		// element = 0b1011;
		//TODO: FIND A PATTERN FOR THE 3 LEFTOVER METHODS
		element = 0b0011;
		element = 0b0111;
		element = 0b1011;
		//
		element = 0b0010;
		element = 0b0100;
		element = 0b0101;
		element = 0b1000;
		element = 0b1001;
		element = 0b1010;
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
	printf("zsh:%i", argc);
	stacks = ft_calloc(1, sizeof(t_stacks));
	if (stacks == NULL)
		call_error();
	stacks->a = ft_calloc(argc - 1, sizeof(int *));
	stacks->b = ft_calloc(argc - 1, sizeof(int *));
	if (stacks->a == NULL || stacks->b == NULL)
		call_error();
	stacks->size = argc - 1;
	stacks->top_a = 0;
	stacks->top_b = 0;
	parse_args(argc, argv, stacks->a);
	execute(stacks);
	validate(stacks);
	clean_stacks(stacks, argc);
	return (0);
}
