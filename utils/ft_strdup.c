/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:36:02 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/01/07 00:46:08 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

char	*ft_strdup(const char *src)
{
	char	*p;
	int		i;

	i = 0;
	while (src[i] != '\0')
		i++;
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (!(p))
		return (NULL);
	p[i] = '\0';
	while (i >= 0)
	{
		p[i] = src[i];
		i--;
	}
	return (p);
}
