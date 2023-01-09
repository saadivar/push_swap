/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:59:54 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/01/08 05:21:02 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	algo3(t_list **a, t_list **b)
{
	if ((*a)->content > (*a)->next->content
		&& (*a)->content < (*a)->next->next->content)
		sa(a, b);
	else if ((*a)->content > (*a)->next->next->content
		&& (*a)->content > (*a)->next->content
		&& (*a)->next->content > (*a)->next->next->content)
	{
		sa(a, b);
		rra(a, b);
	}
	else if ((*a)->content > (*a)->next->content
		&& (*a)->next->content < (*a)->next->next->content)
		ra(a, b);
	else if ((*a)->content < (*a)->next->content
		&& (*a)->content < (*a)->next->next->content
		&& (*a)->next->content > (*a)->next->next->content)
	{
		sa(a, b);
		ra(a, b);
	}
	else if ((*a)->content > (*a)->next->next->content
		&& (*a)->next->content > (*a)->next->next->content)
		rra(a, b);
}

int	smallindex1(t_list **a, t_list **b, int *alldigit)
{
	int		i;
	t_list	*tmp;
	int		j;
	int		len;

	(void)(*b);
	i = 0;
	j = 1;
	len = ft_lstsize(*a);
	tmp = (*a);
	while (i < len)
	{
		if ((tmp)->content == alldigit[1])
			return (j);
		else
		{
			i++;
			j++;
			(tmp) = (tmp)->next;
		}
	}
	return (0);
}

void	algo5first(t_list **a, t_list **b, int *arr)
{
	int	k;
	int	len;
	int	j;

	k = 0;
	len = 0;
	len = ft_lstsize(*a);
	j = smallindex(a, b, arr);
	while ((*a)->content != arr[0])
	{
		k = len / 2;
		if (j > k)
			rra(a, b);
		else
			ra(a, b);
	}
	pb(a, b);
}

void	algo5second(t_list **a, t_list **b, int args, int *arr)
{
	int	k;
	int	len;
	int	j;

	k = 0;
	len = 0;
	j = 0;
	len = ft_lstsize(*a);
	if (args == 5)
	{
		j = smallindex1(a, b, arr);
		while ((*a)->content != arr[1])
		{
			k = len / 2;
			if (j > k)
				rra(a, b);
			else
				ra(a, b);
		}
		pb(a, b);
	}
}

void	algo5(t_list **a, t_list **b, int args, int *arr)
{
	algo5first(a, b, arr);
	if (args == 5)
		algo5second(a, b, args, arr);
	algo3(a, b);
	pa(a, b);
	pa(a, b);
}
