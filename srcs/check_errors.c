/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboratko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:07:30 by nboratko          #+#    #+#             */
/*   Updated: 2022/01/06 18:35:25 by nboratko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_doubles(int n, char **args, int index)
{
	index++;
	while (args[index])
	{
		if (ft_atoi(args[index]) == n)
			return (1);
		index++;
	}
	return (0);
}

static int	check_num(char *n)
{
	int	i;

	i = 0;
	if (n[i] == '-')
		i++;
	while (n[i])
	{
		if (!ft_isdigit(n[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_args(int ac, char **av)
{
	int		i;
	char	**args;
	long	tmp;

	i = 0;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
	{
		i = 1;
		args = av;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!check_num(args[i]) || check_doubles(tmp, args, i)
			|| (tmp > INT_MAX || tmp < INT_MIN))
		{
			ft_putendl_fd("Error", 1);
			exit(0);
		}
		i++;
	}
}
