#include "push_swap.h"
#include "libft/libft.h"
#include "stdlib.h"

void	call_error(void)
{
	exit(1);
}

int	is_number(char *str)
{
	if (str == NULL || (*str != '-' && !ft_isdigit(*str)))
		return (0);
	str++;
	while (ft_isdigit(*str))
		str++;
	return (*str == '\0');
}

t_list	*parse_args(int argc, char *argv[])
{
	t_list	*first;
	t_list	*relative;
	int		i;
	int		numb;

	i = 0;
	numb = 0;
	if (argv[i])
	first = ft_lstnew(NULL);//eaugh
	if (first == NULL)
		return (NULL);
	relative = first;
	while (i < argc)
	{

	}
	return (first);
}

int	main(int argc, char *argv[])
{
	t_list	*numbs;

	numbs = parse_args(argc, argv);
	if (numbs == NULL)
		call_error();
}
