

#include "push_swap.h"

void	print_error()
{
	write(1, "Error\n", 6);
	exit(1);
}

void	check_int_max_min(char *str)
{
	int	i;
	int	digits;

	i = 0;
	digits = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			digits++;
		i++;
	}
	if (digits > 10)
		print_error();
	else if (digits == 10)
		if ((str[0] == '-' && str[10] > '8') ||
			(str[0] == '+' && str[10] > '7') ||
			(ft_isdigit(str[0]) && str[9] > '7'))
			print_error();
}

static void	check_duplicate(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		check_int_max_min(argv[i]);
		j = i;
		while (++j < argc)
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				print_error();
	}
}

void	check_arg(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		if ((argv[i][0] == '-' || argv[i][0] == '+'))
			j++;
		while (argv[i][++j])
			if (argv[i][j] < '0' || argv[i][j] > '9')
				print_error();
	}
	check_duplicate(argc, argv);
}
