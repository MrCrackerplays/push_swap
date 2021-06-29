#include "push_swap_sorting.h"
#include "push_swap_utils.h"
#include "stdlib.h"
#include "stdio.h"

// void	print_stacks(t_stacks_holder *stacks)
// {
// 	int	i;

// 	i = 0;
// 	while (i < stacks->size_a || i < stacks->size_b)
// 	{
// 		if (i < stacks->size_a)
// 		{
// 			printf("%3i|", stacks->a->tag);
// 			stacks->a = stacks->a->next;
// 		}
// 		else
// 			printf("   |");
// 		if (i < stacks->size_b)
// 		{
// 			printf("%3i", stacks->b->tag);
// 			stacks->b = stacks->b->next;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }

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
	int		i;

	printf("pre tag:%i | exponent:%i | base:%i | a:%i ?= digit:%i\n", origin->tag, number_holder->exponent, number_holder->base, ((origin->tag / number_holder->exponent) % number_holder->base), number_holder->digit);
	// if (origin == stacks->a)
	// 	printf("to_b\n");
	// else
	// 	printf("to_a\n");
	// print_stacks(stacks);
	while (((origin->tag / number_holder->exponent)
			% number_holder->base) != number_holder->digit)
	{
		printf("tag:%i | exponent:%i | base:%i | a:%i != digit:%i\n", origin->tag, number_holder->exponent, number_holder->base, ((origin->tag / number_holder->exponent) % number_holder->base), number_holder->digit);
		origin = origin->next;
	}
	// printf("post\n");
	stack = stacks->b;
	if (direction == to_b)
		stack = stacks->a;
	forward_rotations = 0;
	i = 0;
	while (stack->tag != origin->tag)
	{
		if (direction == to_b)
		{
			stack = stack->next;
			forward_rotations++;
		}
		else
		{
			stack = stack->previous;
			forward_rotations--;
		}
		
	}
	size = stacks->size_b;
	if (direction == to_b)
		size = stacks->size_a;
	return (execute_rotations(stacks, direction, size, forward_rotations));
}

t_list	*push_all_of_digit_to_a(t_stacks_holder *stacks, int amount,
		t_number_base_info *base_info)
{
	t_list	*actions;
	int		moves_left;

	actions = NULL;
	moves_left = stacks->size_b;
	while (amount > 0)
	{
		while (((stacks->b->tag / base_info->exponent)
				% base_info->base) != base_info->digit)
		{
			ft_lstadd_back(&actions, call_operation(stacks, "rb\n",
					rotate_b, 1));
			moves_left--;
		}
		ft_lstadd_back(&actions, call_operation(stacks, "pa\n", push_a, 1));
		amount--;
		moves_left--;
	}
	free(base_info);
	while (moves_left > 0)
	{
		ft_lstadd_back(&actions, call_operation(stacks, "rb\n",rotate_b, 1));
		moves_left--;
	}
	return (actions);
}

t_list	*push_all_of_digit_to_b(t_stacks_holder *stacks, int amount,
		t_number_base_info *base_info)
{
	t_list	*actions;
	int		moves_left;

	actions = NULL;
	moves_left = stacks->size_a;
	// printf("voor, movesleft:%i\n", moves_left);
	// print_stacks(stacks);
	while (amount > 0)
	{
		while (((stacks->a->tag / base_info->exponent)
				% base_info->base) != base_info->digit)
		{
			ft_lstadd_back(&actions, call_operation(stacks, "ra\n",
					rotate_a, 1));
			moves_left--;
		}
		ft_lstadd_back(&actions, call_operation(stacks, "pb\n", push_b, 1));
		amount--;
		moves_left--;
	}
	free(base_info);
	// printf("tussen, movesleft:%i\n", moves_left);
	// print_stacks(stacks);
	while (moves_left > 0)
	{
		ft_lstadd_back(&actions, call_operation(stacks, "ra\n",rotate_a, 1));
		moves_left--;
	}
	// printf("na, movesleft:%i\n", moves_left);
	// print_stacks(stacks);
	return (actions);
}

t_list	*push_all_of_digit(t_stacks_holder *stacks, int amount,
		t_number_base_info *base_info, t_direction direction)
{
	if (direction == to_a)
		return (push_all_of_digit_to_a(stacks, amount, base_info));
	return (push_all_of_digit_to_b(stacks, amount, base_info));
}
