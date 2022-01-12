/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboratko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:04:11 by nboratko          #+#    #+#             */
/*   Updated: 2022/01/07 19:20:39 by nboratko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sort(t_list **stack)
{
	t_list	*alst;

	alst = *stack;
	while (alst && alst->next)
	{
		if (alst->value > alst->next->value)
			return (0);
		alst = alst->next;
	}
	return (1);
}

void	st_free(t_list **stack)
{
	t_list	*alst;
	t_list	*tmp;

	alst = *stack;
	while (alst)
	{
		tmp = alst;
		alst = alst->next;
		free(tmp);
	}
	free(stack);
}

int	find_dist(t_list **stack, int index)
{
	t_list	*alst;
	int		dist;

	alst = *stack;
	dist = 0;
	while (alst)
	{
		if (alst->index == index)
			break ;
		dist++;
		alst = alst->next;
	}
	return (dist);
}

int	is_min(t_list **stack, int value)
{
	t_list	*alst;
	int		min;

	alst = *stack;
	min = alst->index;
	while (alst->next)
	{
		alst = alst->next;
		if (alst->index < min && alst->index != value)
			min = alst->index;
	}
	return (min);
}
