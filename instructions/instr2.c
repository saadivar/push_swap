/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:46:32 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/01/09 00:24:16 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ra(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*tmp1;

	(void)(*b);
	if ((*a) && ft_lstsize(*a) > 1)
	{
		tmp = (*a);
		tmp1 = (*a)->next;
		while ((*a)->next != NULL)
			(*a) = (*a)->next;
		(*a)->next = tmp;
		(*a)->next->next = NULL;
		(*a) = tmp1;
		ft_printf("ra\n");
	}
}

void	rb(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*tmp1;

	(void)(*a);
	if ((*b) && ft_lstsize(*b) > 1)
	{
		tmp = (*b);
		tmp1 = (*b)->next;
		while ((*b)->next != NULL)
			(*b) = (*b)->next;
		(*b)->next = tmp;
		(*b)->next->next = NULL;
		(*b) = tmp1;
		ft_printf("rb\n");
	}
}

void	rr(t_list **a, t_list **b)
{
	ra(a, b);
	rb(a, b);
}

void	rra(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*tmp1;

	(void)(*b);
	if (*a && ft_lstsize(*a) >= 2)
	{
		tmp = (*a);
		while ((*a)->next->next != NULL)
			(*a) = (*a)->next;
		tmp1 = (*a)->next;
		(*a)->next = NULL;
		tmp1->next = tmp;
		(*a) = tmp1;
		ft_printf("rra\n");
	}
}

void	rrb(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*tmp1;

	(void)(*a);
	if (*b && ft_lstsize(*b) >= 2)
	{
		tmp = (*b);
		while ((*b)->next->next != NULL)
			(*b) = (*b)->next;
		tmp1 = (*b)->next;
		(*b)->next = NULL;
		tmp1->next = tmp;
		(*b) = tmp1;
		ft_printf("rrb\n");
	}
}
