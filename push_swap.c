#include "push_swap.h"
#include "libft/libft.h"

int	main(int argc, char *argv[])
{
	int	**a;
	int	**b;

	if (argc < 2)
		call_error();
	a = ft_calloc(argc - 1, sizeof(int *));
	b = ft_calloc(argc - 1, sizeof(int *));
	parse_args(argc, argv, &a);
}
