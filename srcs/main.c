/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboratko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:07:50 by nboratko          #+#    #+#             */
/*   Updated: 2022/01/07 17:28:27 by nboratko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_list	*get_next_index(t_list **stack)
{
	int		is_next;
	t_list	*alst;
	t_list	*next;

	is_next = 0;
	alst = *stack;
	next = NULL;
	if (alst)
	{
		while (alst)
		{
			if (alst->index == -1
				&& (is_next == 0 || next->value > alst->value))
			{
				next = alst;
				is_next = 1;
			}
			alst = alst->next;
		}
	}
	return (next);
}

static void	st_index(t_list **stack)
{
	t_list	*alst;
	int		index;

	index = 0;
	alst = get_next_index(stack);
	while (alst)
	{
		alst->index = index;
		alst = get_next_index(stack);
		index++;
	}
}

static void	st_sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

static void	stack_init(t_list **stack, int ac, char **av)
{
	int		i;
	t_list	*new;
	char	**args;
	int		value;

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
		value = ft_atoi(args[i]);
		new = ft_lstnew(value);
		ft_lstadd_back(stack, new);
		i++;
	}
	st_index(stack);
	if (ac == 2)
		free(args);
}

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (ac < 2)
		return (-1);
	check_args(ac, av);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	stack_init(stack_a, ac, av);
	if (is_sort(stack_a))
	{
		st_free(stack_a);
		st_free(stack_b);
		return (0);
	}
	st_sort(stack_a, stack_b);
	st_free(stack_a);
	st_free(stack_b);
	return (0);
}
