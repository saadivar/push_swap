/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:01:05 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/01/07 00:47:20 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*addl;

	addl = 0;
	if (*lst == NULL)
	{
		new->next = NULL;
		*lst = new;
	}
	else
	{
		addl = ft_lstlast(*lst);
		addl->next = new;
	}
}
