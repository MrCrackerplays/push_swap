#include "universal_stacks.h"
#include "push_swap_utils.h"
#include "push_swap_sorting.h"

t_list	*rotate_to_first_of_digit(t_stacks_holder *stacks, int digit,
		t_direction direction, t_stack *origin)//TODO fix not having base and exponent (to get digit of any number in stack) by using a new struct
{
	t_list	*actions;

	actions = NULL;
	return (actions);
}

t_list	*push_all_of_digit(t_stacks_holder *stacks, int digit,
		t_direction direction, int amount)//TODO fix not having base and exponent (to get digit of any number in stack) by using a new struct
{
	t_list	*actions;

	actions = NULL;
	while (amount > 0)
	{
		while (stacks->a->tag)
		amount--;
	}
	return (actions);
}

int	*count_occurances(t_stacks_holder *stacks,
		t_direction direction, int exponent, const int base)
{
	t_stack	*stack;
	int		*count;
	int		i;

	count = ft_calloc(base, sizeof(int));
	if (count == NULL)
		call_error();
	if (direction == to_b)
		stack = stacks->a;
	else
		stack = stacks->b;
	count[(stack->tag / exponent) % base]++;
	stack = stack->next;
	while (stack != stacks->a && stack != stacks->b)
	{
		count[(stack->tag / exponent) % base]++;
		stack = stack->next;
	}
	return (count);
}

t_list	*count_sort(t_stacks_holder *stacks, t_direction dir, int exponent,
		const int base)
{
	int		digit;
	int		*count;
	t_list	*actions;
	t_stack	*origin;

	count = count_occurances(stacks, dir, exponent, base);
	digit = 0;
	actions = NULL;
	if (dir == to_b)
		origin = stacks->a;
	else
		origin = stacks->b;
	while (digit < base)
	{
		if (count[digit] > 0)
		{
			ft_lstadd_back(&actions, rotate_to_first_of_digit(stacks, digit,
					dir, origin));
			ft_lstadd_back(&actions, push_all_of_digit(stacks, digit, dir,
					count[digit]));
		}
		digit++;
	}
	free(count);
	return (actions);
}

t_list	*radix_sort(t_stacks_holder *stacks)
{
	int			exponent;
	int			max;
	t_direction	direction;
	t_list		*order;
	const int	base = 4;

	direction = to_b;
	max = stacks->size_a - 1;
	exponent = 1;
	order = NULL;
	while (max / exponent > 0)
	{
		ft_lstadd_back(&order, count_sort(stacks, direction, exponent, base));
		direction = -direction;
		exponent *= base;
	}
	return (order);
}
