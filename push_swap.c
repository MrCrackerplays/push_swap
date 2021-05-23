#include "push_swap.h"
#include "libft/libft.h"
#include "stdlib.h"
#include "unistd.h"

void	call_error(void)
{
	write(1, "Error\n", 6);
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
	int	i;

	i = 1;
	if (argc < 2)
		call_error();
	while (i < argc)
	{
		if (!is_number(argv[i]))
			call_error();
		;//voeg de nummers via atoi toe aan een stack (maken via malloc), todo: beslis of het een stack van int* of int wordt
		//misschien de returntype van parse_args aanpassen? idk
		i++;
	}

	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_list	*numbs;

	numbs = parse_args(argc, argv);
	if (numbs == NULL)
		call_error();
	//magic calculating which commands to execute (sa, sb, .., rrb, rrr) in what order
}
