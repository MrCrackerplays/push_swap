#include "push_swap_radix_sorting.h"
#include "push_swap_utils.h"
#include "stdlib.h"

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
		ft_lstadd_back(&actions, call_operation(stacks, "rb\n", rotate_b, 1));
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
	while (moves_left > 0)
	{
		ft_lstadd_back(&actions, call_operation(stacks, "ra\n", rotate_a, 1));
		moves_left--;
	}
	return (actions);
}
