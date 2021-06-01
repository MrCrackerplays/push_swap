#include "push_swap.h"
#include "libft/libft.h"
#include "stdlib.h"
#include "unistd.h"

void	call_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	is_int(char *str)
{
	int		i;
	char	*cmp;

	if (str == NULL || (*str != '-' && !ft_isdigit(*str)))
		return (0);
	cmp = "2147483647";
	if (*str == '-')
	{
		str++;
		cmp = "2147483648";
	}
	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	return (str[i] == '\0' && i <= 10
		&& (i < 10 || ft_strncmp(str, cmp, 11) <= 0));
}

void	parse_args(int argc, char *argv[], t_stacks_holder *stacks)
{
	int		i;
	t_stack	*a;

	i = 1;
	a = stacks->a;
	while (i < argc)
	{
		if (!is_int(argv[i]))
			call_error();
		a->value = ft_calloc(1, sizeof(int));
		if (a->value == NULL)
			call_error();
		*(a->value) = ft_atoi(argv[i]);
		i++;
		if (i < argc)
		{
			add_element(a);
			a = a->next;
		}
	}
}

void clean_stacks(t_stack *a, t_stack *b)
{
	t_stack	*iter;

	if (a)
	{
		iter = a->next;
		while (iter != a)
		{
			iter = iter->next;
			free(iter->previous);
		}
		free(a);
	}
	if (b)
	{
		iter = b->next;
		while (iter != b)
		{
			iter = iter->next;
			free(iter->previous);
		}
		free(b);
	}
}
