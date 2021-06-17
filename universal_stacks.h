#ifndef UNIVERSAL_STACKS_H
# define UNIVERSAL_STACKS_H

typedef struct s_stack
{
	int				*value;
	unsigned int	tag;
	struct s_stack	*next;
	struct s_stack	*previous;
}				t_stack;
typedef struct s_stacks_holder
{
	t_stack	*a;
	t_stack	*b;
	int		size_a;
	int		size_b;
}				t_stacks_holder;
void			call_error(void);
t_stacks_holder	*setup_stacks(int argc, char *argv[]);
void			clean_stacks(t_stack *a, t_stack *b);
void			push_a(t_stacks_holder *stacks);
void			push_b(t_stacks_holder *stacks);
void			swap_a(t_stacks_holder *stacks);
void			swap_b(t_stacks_holder *stacks);
void			swap_ab(t_stacks_holder *stacks);
void			rotate_a(t_stacks_holder *stacks);
void			rotate_b(t_stacks_holder *stacks);
void			rotate_ab(t_stacks_holder *stacks);
void			reverse_rotate_a(t_stacks_holder *stacks);
void			reverse_rotate_b(t_stacks_holder *stacks);
void			reverse_rotate_ab(t_stacks_holder *stacks);
#endif