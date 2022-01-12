/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboratko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:09:52 by nboratko          #+#    #+#             */
/*   Updated: 2022/01/07 17:06:46 by nboratko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	push(t_list **st_src, t_list **st_dest)
{
	t_list	*alst_src;
	t_list	*alst_dest;
	t_list	*tmp;

	if (ft_lstsize(*st_src) == 0)
		return (-1);
	alst_src = *st_src;
	alst_dest = *st_dest;
	tmp = alst_src;
	alst_src = alst_src->next;
	*st_src = alst_src;
	if (!alst_dest)
	{
		alst_dest = tmp;
		alst_dest->next = NULL;
		*st_dest = alst_dest;
	}
	else
	{
		tmp->next = alst_dest;
		*st_dest = tmp;
	}
	return (0);
}

int	ft_pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	ft_pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}
