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

t_list	*count_sort(t_stacks_holder *stacks, int direction, int exponent)
{
	int	i;
	int	*count;

	i = 0;
	count = ft_calloc(10, sizeof(int));
	if (count == NULL)
		call_error();
	//TODO FINISH METHOD
}

int	get_minmax(t_stack *stack, int size)
{
	int	min;
	int	max;
	int	i;

	i = 0;
	min = 0;
	max = 0;
	while (i < size)
	{
		if (min > *stack->value)
			min = *stack->value;
		if (max < *stack->value)
			max = *stack->value;
		stack = stack->next;
		i++;
	}
	if (min < -max)
		return (min);
	return (max);
}

t_list	*radix_sort(t_stacks_holder *stacks)
{
	int		direction;
	int		minmax;
	int		exponent;
	t_list	*order;

	if (direction == 1)
		minmax = get_minmax(stacks->a, stacks->size_a);
	else
		minmax = get_minmax(stacks->b, stacks->size_b);
	exponent = 1;
	order = NULL;
	direction = 1;
	while (minmax / exponent > 0)
	{
		ft_lstadd_back(&order, count_sort(stacks, direction, exponent));
		direction = -direction;
		exponent *= 10;
	}
}
