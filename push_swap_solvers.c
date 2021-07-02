#include "push_swap_utils.h"
#include "push_swap_sorting.h"

t_list	*solve_three(t_stacks_holder *stacks, int amount)
{
	t_list	*actions;

	actions = NULL;
	if (amount == 1)
		return (NULL);
	if (amount == 2 && *(stacks->a->value) > *(stacks->a->next->value))
		return (call_operation(stacks, "ra\n", rotate_a, 1));
	if (amount == 2)
		return (NULL);
	if (((*(stacks->a->value) > *(stacks->a->next->value))
			+ (*(stacks->a->next->value) > *(stacks->a->previous->value))
			+ (*(stacks->a->previous->value) > *(stacks->a->value))) == 2)
		ft_lstadd_back(&actions, call_operation(stacks, "sa\n", swap_a, 1));
	if (*(stacks->a->previous->value) > *(stacks->a->value)
		&& *(stacks->a->value) < *(stacks->a->next->value)
		&& *(stacks->a->next->value) < *(stacks->a->previous->value))
		return (actions);
	if (*(stacks->a->value) > *(stacks->a->next->value))
		ft_lstadd_back(&actions, call_operation(stacks, "ra\n", rotate_a, 1));
	else
		ft_lstadd_back(&actions, call_operation(stacks, "rra\n",
				reverse_rotate_a, 1));
	return (actions);
}

t_stack	*insert_back_to_a(t_stacks_holder *stacks, int amount, t_list **cmmnds)
{
	t_stack	*a;

	a = stacks->a;
	while (stacks->size_a != amount)
	{
		if (stacks->a == a
			&& *(stacks->b->value) > *(stacks->a->previous->value))
			ft_lstadd_back(cmmnds, call_operation(stacks, "pa\n", push_a, 1));
		else if (stacks->a == a
			&& *(stacks->b->value) < *(stacks->a->value))
		{
			ft_lstadd_back(cmmnds, call_operation(stacks, "pa\n", push_a, 1));
			a = stacks->a;
		}
		else if (*(stacks->a->previous->value) < *(stacks->b->value)
			&& *(stacks->b->value) < *(stacks->a->value))
			ft_lstadd_back(cmmnds, call_operation(stacks, "pa\n", push_a, 1));
		else if (*(stacks->b->value) < *(stacks->a->value)
			&& *(stacks->b->value) < *(stacks->a->next->value))
			ft_lstadd_back(cmmnds, call_operation(stacks, "rra\n",
					reverse_rotate_a, 1));
		else
			ft_lstadd_back(cmmnds, call_operation(stacks, "ra\n", rotate_a, 1));
	}
	return (a);
}

t_list	*solve_small(t_stacks_holder *stacks, int amount)
{
	t_list	*actions;
	t_stack	*a;
	int		i;

	actions = NULL;
	if (amount > 3)
	{
		actions = call_operation(stacks, "pb\n", push_b, amount - 3);
		ft_lstadd_back(&actions, solve_three(stacks, 3));
	}
	else
		return (solve_three(stacks, amount));
	a = insert_back_to_a(stacks, amount, &actions);
	i = 0;
	while (a != stacks->a)
	{
		a = a->previous;
		i++;
	}
	if (i < amount - i)
		ft_lstadd_back(&actions, call_operation(stacks, "ra\n", rotate_a, i));
	else
		ft_lstadd_back(&actions, call_operation(stacks, "rra\n",
				reverse_rotate_a, amount - i));
	return (actions);
}

/*
 *	max amount of actions using radix https://www.geogebra.org/m/ymxz5htp
 */

t_list	*solve_n(t_stacks_holder *stacks, int amount)
{
	t_list		*actions;
	const int	base = 4;

	actions = radix_sort(stacks, amount, base);
	ft_lstadd_back(&actions, call_operation(stacks, "pa\n", push_a,
			stacks->size_b));
	return (actions);
}
