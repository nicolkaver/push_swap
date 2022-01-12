/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboratko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:03:18 by nboratko          #+#    #+#             */
/*   Updated: 2022/01/06 19:22:39 by nboratko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../libft/libft.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

int		main(int ac, char **av);
void	check_args(int ac, char **av);
int		is_sort(t_list **stack);
void	st_free(t_list **stack);
int		find_dist(t_list **stack, int index);
int		is_min(t_list **stack_a, int value);
void	radix_sort(t_list **stack_a, t_list **stack_b);
void	simple_sort(t_list **stack_a, t_list **stack_b);
int		push(t_list **st_src, t_list **st_dest);
int		ft_pa(t_list **stack_a, t_list **stack_b);
int		ft_pb(t_list **stack_a, t_list **stack_b);
int		rotate(t_list **stack);
int		ft_ra(t_list **stack_a);
int		ft_rb(t_list **stack_b);
int		ft_rr(t_list **stack_a, t_list **stack_b);
int		rev_rotate(t_list **stack);
int		ft_rra(t_list **stack_a);
int		ft_rrb(t_list **stack_b);
int		swap(t_list **stack);
int		ft_sa(t_list **stack_a);
int		ft_sb(t_list **stack_b);
int		ft_ss(t_list **stack_a, t_list **stack_b);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstadd_back(t_list **alst, t_list *new);

#endif
