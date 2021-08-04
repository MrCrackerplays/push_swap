/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_utils.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/04 13:37:16 by pdruart       #+#    #+#                 */
/*   Updated: 2021/08/04 13:37:17 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H
# include "universal_stacks.h"
# include "libft/libft.h"

t_list	*call_operation(t_stacks_holder *stacks, char *print,
			void (*oper)(t_stacks_holder *), int count);
void	print_commands(t_list *commands);

#endif