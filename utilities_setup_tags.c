#include "utilities_setup_tags.h"
#include "libft/libft.h"
#include "stdlib.h"

int	*fill_arr(int argc, char *argv[])
{
	int	*arr;
	int	i;

	i = 1;
	arr = ft_calloc(argc - 1, sizeof(int));
	if (arr == NULL)
		call_error();
	while (i < argc)
	{
		arr[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (arr);
}

void	insertion_sort_arr(int *arr, int argc)
{
	int	i;
	int	holder;

	i = 0;
	while (i < argc - 1)
	{
		while (i > 0 && arr[i] < arr[i - 1])
		{
			holder = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = holder;
			i--;
		}
		i++;
	}
}

void	apply_tags(t_stacks_holder *stacks, int *arr, int argc)
{
	int		i;
	t_stack	*node;

	i = 0;
	node = stacks->a;
	while (i < argc - 1)
	{
		while (node->value != arr[i])
			node = node->next;
		node->tag = i;
		i++;
	}
}

void	add_tags(t_stacks_holder *stacks, int argc, char *argv[])
{
	int		*arr;

	arr = fill_arr(argc, argv);
	insertion_sort_arr(arr, argc);
	apply_tags(stacks, arr, argc);
	free(arr);
}
