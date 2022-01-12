/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboratko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:05:25 by nboratko          #+#    #+#             */
/*   Updated: 2022/01/06 15:15:39 by nboratko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_bits_len(t_list **stack)
{
	t_list	*alst;
	int		len;
	int		bits_len;

	alst = *stack;
	len = alst->index;
	bits_len = 0;
	while (alst)
	{
		if (alst->index > len)
			len = alst->index;
		alst = alst->next;
	}
	while ((len >> bits_len) != 0)
		bits_len++;
	return (bits_len);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*alst_a;
	int		i;
	int		j;
	int		size;
	int		bits_len;

	alst_a = *stack_a;
	i = 0;
	size = ft_lstsize(alst_a);
	bits_len = get_bits_len(stack_a);
	while (i < bits_len)
	{
		j = -1;
		while (++j < size)
		{
			alst_a = *stack_a;
			if (((alst_a->index >> i) & 1) == 1)
				ft_ra(stack_a);
			else
				ft_pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			ft_pa(stack_a, stack_b);
		i++;
	}
}
