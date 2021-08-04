/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/04 13:39:26 by pdruart       #+#    #+#                 */
/*   Updated: 2021/08/04 13:39:26 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "universal_stacks.h"
#include "stddef.h"

void	swap_a(t_stacks_holder *stacks)
{
	t_stack	*original;

	if (stacks->a == NULL || stacks->a == stacks->a->next)
		return ;
	original = stacks->a;
	stacks->a = original->next;
	original->next = stacks->a->next;
	stacks->a->previous = original->previous;
	original->previous = stacks->a;
	stacks->a->next = original;
	stacks->a->previous->next = stacks->a;
	original->next->previous = original;
}

void	swap_b(t_stacks_holder *stacks)
{
	t_stack	*original;

	if (stacks->b == NULL || stacks->b == stacks->b->next)
		return ;
	original = stacks->b;
	stacks->b = original->next;
	original->next = stacks->b->next;
	stacks->b->previous = original->previous;
	original->previous = stacks->b;
	stacks->b->next = original;
	stacks->b->previous->next = stacks->b;
	original->next->previous = original;
}

void	swap_ab(t_stacks_holder *stacks)
{
	swap_a(stacks);
	swap_b(stacks);
}
