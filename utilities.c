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

void	parse_args(int argc, char *argv[], int **a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_int(argv[i]))
			call_error();
		a[i - 1] = ft_calloc(1, sizeof(int));
		if (a[i - 1] == NULL)
			call_error();
		*(a[i - 1]) = ft_atoi(argv[i]);
		i++;
	}
}

void	clean_stacks(t_stacks *stacks, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if ((stacks->a)[i])
			free((stacks->a)[i]);
		if ((stacks->b)[i])
			free((stacks->b)[i]);
		i++;
	}
	free(stacks->a);
	free(stacks->b);
	free(stacks);
}
