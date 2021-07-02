#include "universal_stacks.h"
#include "push_swap_utils.h"
#include "push_swap_sorting.h"
#include "stdlib.h"

t_number_base_info	*create_base_info(const int base, int exponent, int digit)
{
	t_number_base_info	*base_info;

	base_info = ft_calloc(1, sizeof(t_number_base_info));
	if (base_info == NULL)
		call_error();
	base_info->base = base;
	base_info->digit = digit;
	base_info->exponent = exponent;
	return (base_info);
}

int	*count_occurances(t_stacks_holder *stacks,
		t_direction direction, int exponent, const int base)
{
	t_stack	*stack;
	int		*count;

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
	t_list	*(*push_all_of_digit)(t_stacks_holder *, int, t_number_base_info *);

	count = count_occurances(stacks, dir, exponent, base);
	digit = (dir == to_a) * (base - 1);
	actions = NULL;
	push_all_of_digit = push_all_of_digit_to_a;
	if (dir == to_b)
		push_all_of_digit = push_all_of_digit_to_b;
	while ((dir == to_b && digit < base) || (dir == to_a && digit >= 0))
	{
		if (count[digit] > 0)
			ft_lstadd_back(&actions, push_all_of_digit(stacks, count[digit],
					create_base_info(base, exponent, digit)));
		digit += dir;
	}
	free(count);
	return (actions);
}

t_list	*radix_sort(t_stacks_holder *stacks, int max, const int base)
{
	int			exponent;
	t_direction	direction;
	t_list		*order;

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
