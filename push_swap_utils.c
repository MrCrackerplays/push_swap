#include "push_swap.h"

// void	print_stacks(t_stacks_holder *stacks)
// {
// 	int	i;

// 	i = 0;
// 	while (i < stacks->size_a || i < stacks->size_b)
// 	{
// 		if (i < stacks->size_a)
// 		{
// 			printf("%3i|", *stacks->a->value);
// 			stacks->a = stacks->a->next;
// 		}
// 		if (i < stacks->size_b)
// 		{
// 			printf("%3i", *stacks->b->value);
// 			stacks->b = stacks->b->next;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }

t_list	*call_operation(t_stacks_holder *stacks, char *print,
	void (*oper)(t_stacks_holder *), int count)
{
	int		i;
	t_list	*lst;
	t_list	*temp;

	i = 0;
	lst = NULL;
	while (i < count)
	{
		oper(stacks);
		temp = ft_lstnew(print);
		if (temp == NULL)
			call_error();
		ft_lstadd_back(&lst, temp);
		i++;
	}
	return (lst);
}

int	*count_occurrances(t_stacks_holder *stacks,
				int direction, int exponent)
{
	t_stack	*stack;
	int		*count;

	count = ft_calloc(2, sizeof(int));
	if (count == NULL)
		call_error();
	if (direction == 1)
		stack = stacks->a;
	else
		stack = stacks->b;
	count[(stack->tag / exponent) & 1]++;
	stack = stack->next;
	while (stack != stacks->a && stack != stacks->b)
	{
		count[(stack->tag / exponent) & 1]++;
		stack = stack->next;
	}
	return (count);
}

t_list	*count_sort(t_stacks_holder *stacks, int direction, int exponent)
{
	int			i;
	int			*count;

	i = 0;
	count = count_occurrances(stacks, direction, exponent);
	if (direction == 1 || stacks || exponent)
	{
		while (i < stacks->size_a) i++;
	}
	free(count);
	return (NULL);
	//TODO FINISH METHOD
}

int	get_max(t_stack *stack, int size)
{
	unsigned int	max;
	int				i;

	i = 0;
	max = 0;
	while (i < size)
	{
		if (max < stack->tag)
			max = stack->tag;
		stack = stack->next;
		i++;
	}
	return (max);
}

t_list	*radix_sort(t_stacks_holder *stacks)
{
	int		direction;
	int		exponent;
	int		max;
	t_list	*order;

	direction = 1;
	if (direction == 1)
		max = get_max(stacks->a, stacks->size_a);
	else
		max = get_max(stacks->b, stacks->size_b);
	exponent = 1;
	order = NULL;
	while (max / exponent > 0)
	{
		ft_lstadd_back(&order, count_sort(stacks, direction, exponent));
		direction = -direction;
		exponent *= 2;
	}
	return (order);
}
