#include "push_swap_utils.h"
#include "unistd.h"

// void	print_stacks(t_stacks_holder *stacks)
// {
// 	int	i;

// 	i = 0;
// 	while (i < stacks->size_a || i < stacks->size_b)
// 	{
// 		if (i < stacks->size_a)
// 		{
// 			printf("%3i|", *stacks->a->value);
// 			stacks->a = stacks->a->next;
// 		}
// 		if (i < stacks->size_b)
// 		{
// 			printf("%3i", *stacks->b->value);
// 			stacks->b = stacks->b->next;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }

t_list	*call_operation(t_stacks_holder *stacks, char *print,
	void (*oper)(t_stacks_holder *), int count)
{
	int		i;
	t_list	*lst;
	t_list	*temp;

	i = 0;
	lst = NULL;
	while (i < count)
	{
		oper(stacks);
		temp = ft_lstnew(print);
		if (temp == NULL)
			call_error();
		ft_lstadd_back(&lst, temp);
		i++;
	}
	return (lst);
}

void	print_commands(t_list *commands)
{
	while (commands != NULL)
	{
		write(1, commands->content, ft_strlen(commands->content));
		commands = commands->next;
	}
}
