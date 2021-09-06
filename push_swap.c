/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/04 13:39:02 by pdruart       #+#    #+#                 */
/*   Updated: 2021/09/06 15:31:34 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"
#include "push_swap_solvers.h"
#include "stdlib.h"

int	is_sorted(t_stack *a)
{
	t_stack	*temp;

	temp = a->next;
	while (temp->previous->value < temp->value)
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
		exit(1);
	stacks = setup_stacks(argc, argv);
	if (is_sorted(stacks->a))
		commands = NULL;
	else if (argc - 1 < 10)
		commands = solve_small(stacks, argc - 1);
	else
		commands = solve_n(stacks, argc - 1);
	clean_stacks(stacks->a, stacks->b);
	free(stacks);
	print_commands(commands);
	ft_lstclear(&commands, NULL);
}
