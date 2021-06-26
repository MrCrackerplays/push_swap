#include "universal_stacks.h"
#include "libft/libft.h"
#include "stdlib.h"
#include "stdio.h"

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

void	add_element(t_stack *to_insert_after)
{
	t_stack	*new;

	new = ft_calloc(1, sizeof(t_stack));
	if (new == NULL)
		call_error();
	new->next = to_insert_after->next;
	new->previous = to_insert_after;
	new->next->previous = new;
	to_insert_after->next = new;
}

void	check_duplicate(int i, int argc, char *argv[])
{
	while (i + 1 < argc)
	{
		if (ft_strncmp(argv[i], argv[i + 1], -1) == 0)
			call_error();
		i++;
	}
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
		check_duplicate(i, argc, argv);
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

void	add_tags(t_stacks_holder *stacks, int argc, char *argv[])
{
	int		i;
	int		*arr;
	int		holder;
	t_stack	*node;

	i = 1;
	arr = ft_calloc(argc - 1, sizeof(int));
	if (arr == NULL)
		call_error();
	while (i < argc)
	{
		arr[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	i = 0;
	while (i < argc)
	{
		while (i > 0 && arr[i] < arr[i - 1])
		{
			holder = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = holder;
			i--;
		}
		i++;
	}
	i = 0;
	node = stacks->a;
	printf("1\n");
	while (i < argc)
	{
		while (*(node->value) != arr[i])//infinite loop, idk why yet TODO: fix
			node = node->next;
		node->tag = i;
		i++;
	}
	printf("2\n");
}

t_stacks_holder	*setup_stacks(int argc, char *argv[])
{
	t_stacks_holder	*stacks;
	// t_list			*temp;
	// int				i;

	stacks = ft_calloc(1, sizeof(t_stacks_holder));
	if (stacks == NULL)
		call_error();
	stacks->a = ft_calloc(1, sizeof(t_stack));
	if (stacks->a == NULL)
		call_error();
	stacks->a->next = stacks->a;
	stacks->a->previous = stacks->a;
	parse_args(argc, argv, stacks);
	add_tags(stacks, argc, argv);
	// temp = NULL;
	// i = 0;
	// while (i < argc)
	// {
	// 	ft_lstadd_back(&temp, ft_lstnew(i));//finish fix, make the tags correct
	// }
	return (stacks);
}
