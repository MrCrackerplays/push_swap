#include "push_swap.h"
#include "libft/libft.h"
#include "stdlib.h"
#include "unistd.h"

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

t_list	*solve_three(t_stacks_holder *stacks, int amount)
{
	t_list	*lst;

	lst = NULL;
	if (amount == 1)
		return (NULL);
	if (amount == 2 && *(stacks->a->value) > *(stacks->a->next->value))
		return (call_operation(stacks, "sa\n", swap_a, 1));
	if (amount == 2)
		return (NULL);
	if ((*(stacks->a->value) > *(stacks->a->next->value)
			+ *(stacks->a->next->value) > *(stacks->a->previous->value)
			+ *(stacks->a->previous->value) > *(stacks->a->value)) == 2)
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
	t_list	*temp;

	lst = NULL;
	if (amount > 3)
		lst = call_operation(stacks, "pb\n", push_b, amount - 3);
	if (amount > 3)
		ft_lstadd_back(&lst, solve_three(stacks, 3));
	else
		return (solve_three(stacks, amount));
	//magic sort b into a AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA I dislike thinking of an algorythm
	// if (*(stacks->b->value) > *(stacks->a->previous->value))
	// {
	// 	ft_lstadd_back(&lst, call_operation(stacks, "pa\n", push_a, 1));
	// 	ft_lstadd_back(&lst, call_operation(stacks, "ra\n", rotate_a, 1));
	// }
	while (stacks->size_a != amount)
	{
		while (*(stacks->a->value) < *(stacks->b->value)
				&& (*(stacks->a->value) > *(stacks->a->previous->value)))
			ft_lstadd_back(&lst, call_operation(stacks, "ra\n", rotate_a, 1));
		if (*(stacks->b->value) > *(stacks->a->value))
			ft_lstadd_back(&lst, call_operation(stacks, "pa\n", push_a, 1));
	}
	return (lst);
}

t_list	*solve_n(t_stacks_holder *stacks, int amount)
{
	t_list	*lst;
	t_list	*temp;

	lst = NULL;
	while (stacks->a != NULL)
	{
		;
	}
	while (stacks->b != NULL)
	{
		push_a(stacks);
		temp = ft_lstnew("pa\n");
		if (temp == NULL)
			call_error();
		ft_lstadd_back(&lst, temp);
	}
	return (lst);
}

void	print_commands(t_list *commands)
{
	if (commands == NULL)
		return ;
	print_commands(commands->next);
	write(1, commands->content, ft_strlen(commands->content));
}

int	main(int argc, char *argv[])
{
	t_stacks_holder	*stacks;
	t_list			*commands;

	if (argc < 2)
		call_error();
	stacks = setup_stacks(argc, argv);
	if (argc < 7)
		commands = solve_five(stacks, argc - 1);
	else
		commands = solve_n(stacks, argc - 1);
	clean_stacks(stacks, argc);
	free(stacks);
	print_commands(commands);
	ft_lstclear(&commands, NULL);
}
