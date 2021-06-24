#ifndef PUSH_SWAP_SORTING_H
# define PUSH_SWAP_SORTING_H
# include "universal_stacks.h"
# include "libft/libft.h"

typedef enum e_direction
{
	to_a = -1,
	to_b = 1
}		t_direction;
t_list	*radix_sort(t_stacks_holder *stacks);

#endif