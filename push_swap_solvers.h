#ifndef PUSH_SWAP_SOLVERS_H
# define PUSH_SWAP_SOLVERS_H
# include "universal_stacks.h"
# include "libft/libft.h"

t_list	*solve_small(t_stacks_holder *stacks, int amount);
t_list	*solve_n(t_stacks_holder *stacks, int amount);

#endif