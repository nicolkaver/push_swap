/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboratko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:08:45 by nboratko          #+#    #+#             */
/*   Updated: 2022/01/06 19:35:29 by nboratko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rev_rotate(t_list **stack)
{
	t_list	*alst;
	t_list	*zlst;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	alst = *stack;
	zlst = ft_lstlast(alst);
	while (alst)
	{
		if (alst->next->next == NULL)
		{
			alst->next = NULL;
			break ;
		}
		alst = alst->next;
	}
	zlst->next = *stack;
	*stack = zlst;
	return (0);
}

int	ft_rra(t_list **stack_a)
{
	if (rev_rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	ft_rrb(t_list **stack_b)
{
	if (rev_rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
