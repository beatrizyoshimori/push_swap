

#include "push_swap.h"

static void	check_duplicate(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = i;
		while (++j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				write(1, "Error\n", 6);
				exit(1);
			}
		}
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
		if((argv[i][0] == '-' || argv[i][0] == '+'))
			j++;
		while (argv[i][++j])
		{
			if(argv[i][j] < '0' || argv[i][j] > '9')
			{
				write(1, "Error\n", 6);
				exit(1);
			}
		}
	}
	check_duplicate(argc, argv);
}
