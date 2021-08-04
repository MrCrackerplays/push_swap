/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/04 13:38:56 by pdruart       #+#    #+#                 */
/*   Updated: 2021/08/04 13:38:56 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"
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

void	print_commands(t_list *commands)
{
	while (commands != NULL)
	{
		write(1, commands->content, ft_strlen(commands->content));
		commands = commands->next;
	}
}
