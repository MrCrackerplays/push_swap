#include "checker.h"
#include "push_swap.h"

int	parse_input(char *str)
{
	if (str[0] == 'p')
		return (parse_p(str));
	if (str[0] == 's')
		return (parse_s(str));
	if (str[0] == 'r')
		return (parse_r(str));
	call_error();
	return (-1);
}

int	parse_p(char *str)
{
	if (str[1] == 'a' && str[2] == '\0')
		return (0);
	if (str[1] == 'b' && str[2] == '\0')
		return (1);
	call_error();
	return (-1);
}

int	parse_s(char *str)
{
	if (str[1] == 'a' && str[2] == '\0')
		return (2);
	if (str[1] == 'b' && str[2] == '\0')
		return (3);
	if (str[1] == 's' && str[2] == '\0')
		return (4);
	call_error();
	return (-1);
}

int	parse_r(char *str)
{
	if (str[1] == 'a' && str[2] == '\0')
		return (5);
	if (str[1] == 'b' && str[2] == '\0')
		return (6);
	if (str[1] == 'r')
	{
		if (str[2] == '\0')
			return (7);
		if (str[2] == 'a' && str[3] == '\0')
			return (8);
		if (str[2] == 'b' && str[3] == '\0')
			return (9);
		if (str[2] == 'r' && str[3] == '\0')
			return (10);
	}
	call_error();
	return (-1);
}
