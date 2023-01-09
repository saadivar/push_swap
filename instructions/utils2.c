/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 02:58:16 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/01/09 02:46:29 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rrr(t_list **a, t_list **b)
{
	rra(a, b);
	rrb(a, b);
}

int	posemax(t_list **b, int *arr, int arg)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = (*b);
	while (tmp)
	{
		if (tmp->content == arr[arg])
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

int	poseacct(t_list **a, int nb)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = (*a);
	while (tmp)
	{
		if (tmp->content == nb)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}
