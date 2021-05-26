#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stacks
{
	int	size;
	int	top;
	int	**a;
	int	**b;
}		t_stacks;
void	call_error(void);
void	parse_args(int argc, char *argv[], int **a);
void	clean_stacks(t_stacks *stacks, int argc);
#endif