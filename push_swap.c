#include "push_swap_utils.h"
#include "push_swap_sorting.h"
#include "stdlib.h"

t_list	*solve_three(t_stacks_holder *stacks, int amount)
{
	t_list	*lst;

	lst = NULL;
	if (amount == 1)
		return (NULL);
	if (amount == 2 && *(stacks->a->value) > *(stacks->a->next->value))
		return (call_operation(stacks, "ra\n", rotate_a, 1));
	if (amount == 2)
		return (NULL);
	if (((*(stacks->a->value) > *(stacks->a->next->value))
			+ (*(stacks->a->next->value) > *(stacks->a->previous->value))
			+ (*(stacks->a->previous->value) > *(stacks->a->value))) == 2)
		ft_lstadd_back(&lst, call_operation(stacks, "sa\n", swap_a, 1));
	if (*(stacks->a->previous->value) > *(stacks->a->value)
		&& *(stacks->a->value) < *(stacks->a->next->value)
		&& *(stacks->a->next->value) < *(stacks->a->previous->value))
		return (lst);
	if (*(stacks->a->value) > *(stacks->a->next->value))
		ft_lstadd_back(&lst, call_operation(stacks, "ra\n", rotate_a, 1));
	else
		ft_lstadd_back(&lst, call_operation(stacks, "rra\n",
				reverse_rotate_a, 1));
	return (lst);
}

t_list	*solve_five(t_stacks_holder *stacks, int amount)
{
	t_list	*lst;
	t_stack	*a;
	t_stack	*temp;
	int		i;

	lst = NULL;
	if (amount > 3)
	{
		lst = call_operation(stacks, "pb\n", push_b, amount - 3);
		ft_lstadd_back(&lst, solve_three(stacks, 3));
	}
	else
		return (solve_three(stacks, amount));
	a = stacks->a;
	while (stacks->size_a != amount)
	{
		//if (currpos == first && bval > prevval)
		//	ft_lstadd_back(&lst, call_operation(stacks, "pa\n", push_a, 1));
		if (stacks->a == a
				&& *(stacks->b->value) > *(stacks->a->previous->value))
			ft_lstadd_back(&lst, call_operation(stacks, "pa\n", push_a, 1));
		//else if (currpos == first && bval < currval)
		//{
		//	a = b
		//	ft_lstadd_back(&lst, call_operation(stacks, "pa\n", push_a, 1));
		//}
		else if (stacks->a == a
				&& *(stacks->b->value) < *(stacks->a->value))
		{
			ft_lstadd_back(&lst, call_operation(stacks, "pa\n", push_a, 1));
			a = stacks->a;
		}
		//else if (prevval < bval && bval < currval)
		//	ft_lstadd_back(&lst, call_operation(stacks, "pa\n", push_a, 1));
		else if (*(stacks->a->previous->value) < *(stacks->b->value)
				&& *(stacks->b->value) < *(stacks->a->value))
			ft_lstadd_back(&lst, call_operation(stacks, "pa\n", push_a, 1));
		//else if (bval < currval && bval < nextval)
		//	ft_lstadd_back(&lst, call_operation(stacks, "rra\n",
		//			reverse_rotate_a, 1));
		else if (*(stacks->b->value) < *(stacks->a->value)
				&& *(stacks->b->value) < *(stacks->a->next->value))
			ft_lstadd_back(&lst, call_operation(stacks, "rra\n",
					reverse_rotate_a, 1));
		//else
		//	ft_lstadd_back(&lst, call_operation(stacks, "ra\n", rotate_a, 1));
		else
			ft_lstadd_back(&lst, call_operation(stacks, "ra\n", rotate_a, 1));
	}
	i = 0;
	temp = stacks->a;
	while (temp != a)
	{
		temp = temp->next;
		i++;
	}
	while (stacks->a != a)
	{
		if (i < amount - i)
			ft_lstadd_back(&lst, call_operation(stacks, "ra\n", rotate_a, 1));
		else
			ft_lstadd_back(&lst, call_operation(stacks, "rra\n",
					reverse_rotate_a, 1));
	}
	return (lst);
}

t_list	*solve_n(t_stacks_holder *stacks, int amount)
{
	t_list		*lst;
	const int	base = 4;

	lst = radix_sort(stacks, amount, base);
	ft_lstadd_back(&lst, call_operation(stacks, "pa\n", push_a,
			stacks->size_b));
	return (lst);
}

int	is_sorted(t_stack *a)
{
	t_stack	*temp;

	temp = a->next;
	while (*(temp->previous->value) < *(temp->value))
	{
		if (temp == a)
			return (1);
		temp = temp->next;
	}
	return (temp == a);
}

int	main(int argc, char *argv[])
{
	t_stacks_holder	*stacks;
	t_list			*commands;

	if (argc < 2)
		call_error();
	stacks = setup_stacks(argc, argv);
	if (is_sorted(stacks->a))
		commands = NULL;
	else if (argc - 1 < 8)
		commands = solve_five(stacks, argc - 1);
	else
		commands = solve_n(stacks, argc - 1);
	clean_stacks(stacks->a, stacks->b);
	free(stacks);
	print_commands(commands);
	ft_lstclear(&commands, NULL);
}
