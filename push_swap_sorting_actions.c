#include "push_swap_sorting.h"
#include "push_swap_utils.h"
#include "stdlib.h"

t_list	*execute_rotations(t_stacks_holder *stacks, t_direction direction,
		 int size, int forward_rotations)
{
	t_list	*actions;

	actions = NULL;
	if (direction == to_b)
	{
		if ((size - forward_rotations) < forward_rotations)
			ft_lstadd_back(&actions, call_operation(stacks, "rra\n",
					reverse_rotate_a, size - forward_rotations));
		else
			ft_lstadd_back(&actions, call_operation(stacks, "ra\n",
					rotate_a, forward_rotations));
	}
	else
	{
		if ((size - forward_rotations) < forward_rotations)
			ft_lstadd_back(&actions, call_operation(stacks, "rrb\n",
					reverse_rotate_b, size - forward_rotations));
		else
			ft_lstadd_back(&actions, call_operation(stacks, "rb\n",
					rotate_b, forward_rotations));
	}
	return (actions);
}

t_list	*rotate_to_first_of_digit(t_stacks_holder *stacks, t_stack *origin,
		t_number_base_info *number_holder, t_direction direction)
{
	t_stack	*stack;
	int		forward_rotations;
	int		size;

	stack = stacks->b;
	if (direction == to_b)
		stack = stacks->a;
	size = stacks->size_b;
	if (direction == to_b)
		size = stacks->size_a;
	forward_rotations = 0;
	while (((origin->tag / number_holder->exponent)
			& number_holder->base) != number_holder->digit)
		origin = origin->next;
	while (stack->tag != origin->tag)
	{
		stack = stack->next;
		forward_rotations++;
	}
	return (execute_rotations(stacks, direction, size, forward_rotations));
}

t_list	*push_all_of_digit_to_a(t_stacks_holder *stacks, int amount,
		t_number_base_info *base_info)
{
	t_list	*actions;

	actions = NULL;
	while (amount > 0)
	{
		while (((stacks->a->tag / base_info->exponent)
				& base_info->base) != base_info->digit)
			ft_lstadd_back(&actions, call_operation(stacks, "rb\n",
					rotate_b, 1));
		ft_lstadd_back(&actions, call_operation(stacks, "pa\n",
				push_a, 1));
		amount--;
	}
	free(base_info);
	return (actions);
}

t_list	*push_all_of_digit_to_b(t_stacks_holder *stacks, int amount,
		t_number_base_info *base_info)
{
	t_list	*actions;

	actions = NULL;
	while (amount > 0)
	{
		while (((stacks->a->tag / base_info->exponent)
				& base_info->base) != base_info->digit)
			ft_lstadd_back(&actions, call_operation(stacks, "ra\n",
					rotate_a, 1));
		ft_lstadd_back(&actions, call_operation(stacks, "pb\n",
				push_b, 1));
		amount--;
	}
	free(base_info);
	return (actions);
}

t_list	*push_all_of_digit(t_stacks_holder *stacks, int amount,
		t_number_base_info *base_info, t_direction direction)
{
	if (direction == to_a)
		return (push_all_of_digit_to_a(stacks, amount, base_info));
	return (push_all_of_digit_to_b(stacks, amount, base_info));
}
