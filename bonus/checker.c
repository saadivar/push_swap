/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:11:33 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/01/09 01:07:39 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	stack_is_sorted(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*b)
	{
		ft_printf("KO\n");
		exit(1);
	}
	tmp = *a;
	while (tmp->next != NULL)
	{
		if (tmp->content < tmp->next->content)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	do_ins(char *ins, t_list **a, t_list **b)
{
	if (ft_strcmp(ins, "sa\n") == 0)
		sa(a, b);
	else if (ft_strcmp(ins, "sb\n") == 0)
		sb(a, b);
	else if (ft_strcmp(ins, "ra\n") == 0)
		ra(a, b);
	else if (ft_strcmp(ins, "rb\n") == 0)
		rb(a, b);
	else if (ft_strcmp(ins, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(ins, "rra\n") == 0)
		rra(a, b);
	else if (ft_strcmp(ins, "rrb\n") == 0)
		rrb(a, b);
	else if (ft_strcmp(ins, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(ins, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(ins, "rrr\n") == 0)
		rrr(a, b);
	else if (ft_strcmp(ins, "ss\n") == 0)
		ss(a, b);
	else
		writer();
}

void	readins(int fd, t_list **a, t_list **b)
{
	char	*ins;

	ins = get_next_line(fd);
	while (ins)
	{
		do_ins(ins, a, b);
		free(ins);
		ins = get_next_line(fd);
	}
}

int	main(int ac, char **av)
{
	int		*alldigit;
	t_list	*a;
	t_list	*b;
	int		args;

	if (ac >= 2)
	{
		alldigit = array(ac, av, &args);
		check(args, alldigit, &a, &b);
		readins(0, &a, &b);
		if (stack_is_sorted(&a, &b) == 1)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
}
