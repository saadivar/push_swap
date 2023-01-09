/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:29:41 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/01/09 02:46:36 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	loop1(t_list **a, t_list **b, int args, int *alldigit)
{
	int	z;

	z = 0;
	while ((*b)->content != alldigit[args])
	{
		if ((*b)->content == alldigit[args - 1])
		{
			z = 1;
			pa(a, b);
		}
		else
			rrb(a, b);
	}
	return (z);
}

int	loop2(t_list **a, t_list **b, int args, int *alldigit)
{
	int	z;

	z = 0;
	while ((*b)->content != alldigit[args])
	{
		if ((*b)->content == alldigit[args - 1])
		{
			z = 1;
			pa(a, b);
		}
		else
			rb(a, b);
	}
	return (z);
}

void	from_b_to_a(t_list **a, t_list **b, int args, int *alldigit)
{
	int	z;
	int	pose;

	pose = 0;
	z = 0;
	args = args - 1;
	while (b)
	{
		pose = posemax(b, alldigit, args);
		if (pose >= args / 2)
			z = loop1(a, b, args, alldigit);
		else if (pose < args / 2)
			z = loop2(a, b, args, alldigit);
		pa(a, b);
		args--;
		if (z == 1)
		{
			args--;
			sa(a, b);
			z = 0;
		}
		if (!(*b))
			break ;
	}
}

void	algoover5(t_list **a, t_list **b, int args, int *alldigit)
{
	from_a_to_b(a, b, args, alldigit);
	from_b_to_a(a, b, args, alldigit);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		*alldigit;
	int		args;

	b = NULL;
	args = 0;
	alldigit = array(ac, av, &args);
	check(args, alldigit, &a, &b);
	if (!sorted(alldigit, args))
		exit(0);
	else if (args == 2)
		sa(&a, &b);
	else if (args == 3)
		algo3(&a, &b);
	else if (args <= 5)
		algo5(&a, &b, args, alldigit);
	else if (args > 5)
		algoover5(&a, &b, args, alldigit);
}
