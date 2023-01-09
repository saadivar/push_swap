/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_bonus_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:22:30 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/01/08 22:46:59 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sa(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*tmp1;
	t_list	*tmp2;

	(void)b;
	if (*a && ft_lstsize(*a) > 1)
	{
		tmp = (*a);
		tmp2 = (*a)->next->next;
		tmp1 = (*a)->next;
		*a = tmp1;
		(*a)->next = tmp;
		(*a)->next->next = tmp2;
	}
}

void	sb(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*tmp1;
	t_list	*tmp2;

	(void)a;
	if (*b && ft_lstsize(*b) > 1)
	{
		tmp = (*b);
		tmp2 = (*b)->next->next;
		tmp1 = (*b)->next;
		*b = tmp1;
		(*b)->next = tmp;
		(*b)->next->next = tmp2;
	}
}

void	ss(t_list **a, t_list **b)
{	
	sa(a, b);
	sb(a, b);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*a)
	{
		tmp = (*a);
		*a = (*a)->next;
		ft_lstadd_front(b, tmp);
	}
}

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if ((*b))
	{
		tmp = (*b);
		*b = (*b)->next;
		ft_lstadd_front(a, tmp);
	}
}
