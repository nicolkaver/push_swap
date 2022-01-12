/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboratko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:26:08 by nboratko          #+#    #+#             */
/*   Updated: 2022/01/06 19:16:49 by nboratko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (!new || !alst)
		return ;
	if (*alst == NULL)
	{
		*alst = new;
		(*alst)->next = NULL;
		return ;
	}
	else
	{
		last = ft_lstlast(*alst);
		last->next = new;
		new->next = NULL;
	}
}

void	ft_lstadd_front(t_list	**alst, t_list *new)
{
	if (!new || !alst)
		return ;
	new->next = *alst;
	*alst = new;
}

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = content;
	new->index = -1;
	new->next = NULL;
	return (new);
}

int	ft_lstsize(t_list *lst)
{
	unsigned int	i;
	t_list			*tmp;

	i = 0;
	if (!lst)
		return (i);
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (tmp)
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
	}
	return (tmp);
}
