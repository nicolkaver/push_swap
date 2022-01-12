/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboratko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:09:11 by nboratko          #+#    #+#             */
/*   Updated: 2022/01/06 19:34:11 by nboratko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	swap(t_list **stack)
{
	t_list	*alst;
	t_list	*next;
	int		swap_value;
	int		swap_index;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	alst = *stack;
	next = alst->next;
	if (!alst && !next)
	{
		ft_putstr_fd("Error", 1);
		exit(0);
	}
	swap_value = alst->value;
	swap_index = alst->index;
	alst->value = next->value;
	alst->index = next->index;
	next->value = swap_value;
	next->index = swap_index;
	return (0);
}

int	ft_sa(t_list **stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	ft_sb(t_list **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	ft_ss(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}
