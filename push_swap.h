#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stacks
{
	unsigned int	size;
	unsigned int	amount;
	unsigned int	top_a;
	unsigned int	top_b;
	int				**a;
	int				**b;
}		t_stacks;
void	call_error(void);
void	parse_args(int argc, char *argv[], int **a);
void	clean_stacks(t_stacks *stacks, int argc);
void	push_a(t_stacks *stacks);
void	push_b(t_stacks *stacks);
void	swap_a(t_stacks *stacks);
void	swap_b(t_stacks *stacks);
void	swap_ab(t_stacks *stacks);
void	rotate_a(t_stacks *stacks);
void	rotate_b(t_stacks *stacks);
void	rotate_ab(t_stacks *stacks);
void	reverse_rotate_a(t_stacks *stacks);
void	reverse_rotate_b(t_stacks *stacks);
void	reverse_rotate_ab(t_stacks *stacks);
#endif