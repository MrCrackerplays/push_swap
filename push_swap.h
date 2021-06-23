#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "universal_stacks.h"
# include "libft/libft.h"

t_list	*call_operation(t_stacks_holder *stacks, char *print,
			void (*oper)(t_stacks_holder *), int count);
t_list	*radix_sort(t_stacks_holder *stacks);

#endif