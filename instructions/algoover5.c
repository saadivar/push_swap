/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoover5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 02:23:48 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/01/09 02:44:49 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	data(t_help *p, int args)
{
	p->start = p->start - p->ref;
	p->end = p->end + p->ref;
	if (p->start < 0 && p->end > args - 1)
	{
		p->start = 0;
		p->end = args - 1;
	}
	else if (p->start < 0 || p->end > args - 1)
	{
		if (p->start < 0)
			p->start = 0;
		else
			p->end = args - 1;
	}
}

void	theclosestoper(t_list **a, t_list **b, t_help *p, int *alldigit)
{
	t_list	*tmp;

	tmp = (*a);
	while ((*a) && !((*a)->content >= alldigit[p->start]
			&& (*a)->content <= alldigit[p->end]))
		(*a) = (*a)->next;
	if ((*a) == NULL)
	{
		(*a) = tmp;
		data(p, p->args);
	}
	else if (poseacct(a, (*a)->content) <= ft_lstsize(*a) / 2)
	{
		(*a) = tmp;
		ra(a, b);
	}
	else if (poseacct(a, (*a)->content) > ft_lstsize(*a) / 2)
	{
		(*a) = tmp;
		rra(a, b);
	}
}

void	datahelp(int args, t_help *p)
{
	p->ref = 0;
	p->start = 0;
	p->end = 0;
	if (args <= 10)
		p->ref = args / 5;
	else if (args <= 150)
		p->ref = args / 8;
	else if (args > 150)
		p->ref = args / 18;
	p->start = args / 2 - 1 - p->ref;
	p->end = args / 2 - 1 + p->ref;
}

void	from_a_to_b(t_list **a, t_list **b, int args, int *alldigit)
{
	t_help	p;

	datahelp(args, &p);
	while (*a)
	{
		if ((*a)->content >= alldigit[p.start]
			&& (*a)->content <= alldigit[p.end])
		{
			pb(a, b);
			if (ft_lstsize(*b) > 1 && (*b)->content <= alldigit[args / 2 - 1])
				rb(a, b);
			if (!(*a))
				break ;
		}
		else
		{
			p.args = args;
			theclosestoper(a, b, &p, alldigit);
		}
	}
}
