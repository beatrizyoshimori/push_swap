/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:30:36 by byoshimo          #+#    #+#             */
/*   Updated: 2023/03/17 18:33:18 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static long long	ft_atoll(const char *nptr)
{
	int			sign;
	long long	num;

	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	num = 0;
	while (ft_isdigit(*nptr) == 1)
	{
		num = num * 10 + (*nptr - 48);
		nptr++;
	}
	return (num * sign);
}

static void	check_duplicate(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = i;
		while (++j < argc)
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				print_error();
	}
}

void	check_arg(int argc, char *argv[])
{
	int			i;
	int			j;
	long long	num;

	i = 0;
	while (++i < argc)
	{
		num = ft_atoll(argv[i]);
		if (num > 2147483647 || num < -2147483648)
			print_error();
		j = -1;
		if ((argv[i][0] == '-' || argv[i][0] == '+'))
		{
			if (!argv[i][1])
				print_error();
			j++;
		}
		while (argv[i][++j])
			if (argv[i][j] < '0' || argv[i][j] > '9')
				print_error();
	}
	check_duplicate(argc, argv);
}
