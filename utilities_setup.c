#include "push_swap.h"
#include "libft/libft.h"
#include "stdlib.h"

void	check_int(char *str)
{
	int		i;
	char	*cmp;

	if (str == NULL || (*str == '-' && str[1] == '\0')
		|| (*str != '-' && !ft_isdigit(*str)))
		call_error();
	cmp = "2147483647";
	if (*str == '-')
	{
		str++;
		cmp = "2147483648";
	}
	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0' || i > 10
		|| !(i < 10 || ft_strncmp(str, cmp, 11) <= 0))
		call_error();
}

void	add_element(t_stack *add)
{
	t_stack	*value;

	value = ft_calloc(1, sizeof(t_stack));
	if (value == NULL)
		call_error();
	value->next = add->next;
	value->previous = add;
	add->next->previous = value;
	add->next = value;
}

void	parse_args(int argc, char *argv[], t_stacks_holder *stacks)
{
	int		i;
	t_stack	*a;

	i = 1;
	a = stacks->a;
	while (i < argc)
	{
		check_int(argv[i]);
		a->value = ft_calloc(1, sizeof(int));
		if (a->value == NULL)
			call_error();
		*(a->value) = ft_atoi(argv[i]);
		i++;
		if (i < argc)
		{
			add_element(a);
			a = a->next;
		}
	}
	stacks->size_a = argc - 1;
	stacks->size_b = 0;
}

t_stacks_holder	*setup_stacks(int argc, char *argv[])
{
	t_stacks_holder	*stacks;

	stacks = ft_calloc(1, sizeof(t_stacks_holder));
	if (stacks == NULL)
		call_error();
	stacks->a = ft_calloc(1, sizeof(t_stack));
	if (stacks->a == NULL)
		call_error();
	stacks->a->next = stacks->a;
	stacks->a->previous = stacks->a;
	parse_args(argc, argv, stacks);
	return (stacks);
}
