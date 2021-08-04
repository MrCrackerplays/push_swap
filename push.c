/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/04 13:39:07 by pdruart       #+#    #+#                 */
/*   Updated: 2021/08/04 13:39:08 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "universal_stacks.h"
#include "stddef.h"

void	push_a(t_stacks_holder *stacks)
{
	t_stack	*inbetween;

	if (stacks->b == NULL)
		return ;
	stacks->size_a++;
	stacks->size_b--;
	inbetween = stacks->b;
	stacks->b->previous->next = stacks->b->next;
	stacks->b->next->previous = stacks->b->previous;
	stacks->b = stacks->b->next;
	if (stacks->b == inbetween)
		stacks->b = NULL;
	if (stacks->a == NULL)
	{
		inbetween->previous = inbetween;
		inbetween->next = inbetween;
		stacks->a = inbetween;
		return ;
	}
	stacks->a->previous->next = inbetween;
	inbetween->previous = stacks->a->previous;
	inbetween->next = stacks->a;
	stacks->a->previous = inbetween;
	stacks->a = inbetween;
}

void	push_b(t_stacks_holder *stacks)
{
	t_stack	*inbetween;

	if (stacks->a == NULL)
		return ;
	stacks->size_b++;
	stacks->size_a--;
	inbetween = stacks->a;
	stacks->a->previous->next = stacks->a->next;
	stacks->a->next->previous = stacks->a->previous;
	stacks->a = stacks->a->next;
	if (stacks->a == inbetween)
		stacks->a = NULL;
	if (stacks->b == NULL)
	{
		inbetween->previous = inbetween;
		inbetween->next = inbetween;
		stacks->b = inbetween;
		return ;
	}
	stacks->b->previous->next = inbetween;
	inbetween->previous = stacks->b->previous;
	inbetween->next = stacks->b;
	stacks->b->previous = inbetween;
	stacks->b = inbetween;
}
