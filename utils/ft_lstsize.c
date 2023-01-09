/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:29:38 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/01/07 00:46:05 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ft_lstsize(t_list *lst)
{
	int	total;

	total = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		total++;
	}
	return (total);
}
