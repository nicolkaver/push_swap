/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboratko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:06:02 by nboratko          #+#    #+#             */
/*   Updated: 2022/01/06 19:20:24 by nboratko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_3_part_2(t_list **stack_a, int min)
{
	t_list	*alst;

	alst = *stack_a;
	if (alst->next->index == min)
		ft_ra(stack_a);
	else
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
}

static void	sort_3(t_list **stack_a)
{
	t_list	*alst;
	int		min;
	int		min_2;

	alst = *stack_a;
	min = is_min(stack_a, -1);
	min_2 = is_min(stack_a, min);
	if (alst->index == min && alst->next->index != min_2)
	{
		ft_ra(stack_a);
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (alst->index == min_2)
	{
		if (alst->next->index == min)
			ft_sa(stack_a);
		else
			ft_rra(stack_a);
	}
	else
		sort_3_part_2(stack_a, min);
}

static void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	dist;

	if (is_sort(stack_a))
		return ;
	dist = find_dist(stack_a, is_min(stack_a, -1));
	if (dist == 1)
		ft_ra(stack_a);
	else if (dist == 2)
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	else if (dist == 3)
	{
		ft_rra(stack_a);
	}
	if (is_sort(stack_a))
		return ;
	ft_pb(stack_a, stack_b);
	sort_3(stack_a);
	ft_pa(stack_a, stack_b);
}

static void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	dist;

	dist = find_dist(stack_a, is_min(stack_a, -1));
	if (dist == 1)
		ft_ra(stack_a);
	else if (dist == 2)
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	else if (dist == 3)
	{
		ft_rra(stack_a);
		ft_rra(stack_a);
	}
	else if (dist == 4)
		ft_rra(stack_a);
	if (is_sort(stack_a))
		return ;
	ft_pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	simple_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (is_sort(stack_a) || ft_lstsize(*stack_a) == 1
		|| ft_lstsize(*stack_a) == 0)
		return ;
	if (size == 2)
		ft_sa(stack_a);
	if (size == 3)
		sort_3(stack_a);
	if (size == 4)
		sort_4(stack_a, stack_b);
	if (size == 5)
		sort_5(stack_a, stack_b);
}
