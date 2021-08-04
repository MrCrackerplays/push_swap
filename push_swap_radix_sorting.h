/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_radix_sorting.h                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/04 13:37:05 by pdruart       #+#    #+#                 */
/*   Updated: 2021/08/04 13:37:36 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_RADIX_SORTING_H
# define PUSH_SWAP_RADIX_SORTING_H
# include "universal_stacks.h"
# include "libft/libft.h"

typedef enum e_direction
{
	to_a = -1,
	to_b = 1
}		t_direction;
typedef struct s_number_base_info
{
	unsigned int	base;
	unsigned int	exponent;
	unsigned int	digit;
}		t_number_base_info;

t_list	*radix_sort(t_stacks_holder *stacks, int max, const int base);
t_list	*push_all_of_digit_to_a(t_stacks_holder *stacks, int amount,
			t_number_base_info *base_info);
t_list	*push_all_of_digit_to_b(t_stacks_holder *stacks, int amount,
			t_number_base_info *base_info);

#endif