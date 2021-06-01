#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int		*value;
	t_stack	*next;
	t_stack	*previous;
}		t_stack;
typedef struct s_stacks_holder
{
	t_stack	*a;
	t_stack	*b;
}		t_stacks_holder;
void	call_error(void);
void	parse_args(int argc, char *argv[], t_stacks_holder *stacks);
void	clean_stacks(t_stack *a, t_stack *b);
void	push_a(t_stack **a);
void	push_b(t_stack **b);
void	swap_a(t_stack **a);
void	swap_b(t_stack **b);
void	swap_ab(t_stack **a, t_stack **b);
void	rotate_a(t_stack **a);
void	rotate_b(t_stack **b);
void	rotate_ab(t_stack **a, t_stack **b);
void	reverse_rotate_a(t_stack **a);
void	reverse_rotate_b(t_stack **b);
void	reverse_rotate_ab(t_stack **a, t_stack **b);
#endif