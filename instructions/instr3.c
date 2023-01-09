/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:58:30 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/01/08 04:56:28 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sizearr(int ac, char **av, int *args)
{
	int		i;
	int		j;
	int		k;
	char	**p;

	i = 1;
	j = 0;
	k = 0;
	while (i < ac)
	{
		k = 0;
		p = ft_split(av[i], ' ');
		if (p[0] == '\0')
			writer();
		while (p[k])
		{
			(*args)++;
			free(p[k]);
			k++;
		}
		free(p);
		i++;
	}
}

int	*array(int ac, char **av, int *args)
{
	int		i;
	int		j;
	int		*alldigit;
	int		k;
	char	**p;

	sizearr(ac, av, args);
	alldigit = malloc(4 * (*args));
	j = 0;
	k = 0;
	i = 1;
	while (i < ac)
	{
		k = 0;
		p = ft_split(av[i], ' ');
		while (p[k])
		{
			alldigit[j++] = ft_atoi(p[k]);
			free(p[k]);
			k++;
		}
		free(p);
		i++;
	}
	return (alldigit);
}

int	smallindex(t_list **a, t_list **b, int *alldigit)
{
	int		i;
	t_list	*tmp;
	int		j;
	int		len;

	(void)(*b);
	i = 0;
	j = 0;
	len = ft_lstsize(*a);
	tmp = (*a);
	while (i < len)
	{
		if ((tmp)->content == alldigit[0])
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

int	sorted(int *alldigit, int args)
{
	int	i;
	int	z;
	int	tmp;

	i = 0;
	z = 0;
	while (i < args - 1)
	{
		if (alldigit[i] > alldigit[i + 1])
		{
			tmp = alldigit[i];
			alldigit[i] = alldigit[i + 1];
			alldigit[i + 1] = tmp;
			z++;
			i = 0;
		}
		else
			i++;
	}
	return (z);
}

void	check(int args, int *alldigit, t_list **a, t_list **b)
{
	int	i;

	(void)(*b);
	i = 1;
	checkdouble(args, alldigit);
	*a = ft_lstnew(alldigit[0]);
	while (i < args)
	{
		ft_lstadd_back(a, ft_lstnew(alldigit[i]));
		i++;
	}
}
