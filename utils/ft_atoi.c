/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:41:34 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/01/07 02:22:06 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ft_isspace(int c)
{
	return (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32);
}

void	notdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			writer();
		i++;
	}
}

int	ft_atoi(char *str)
{
	int		sign;
	long	tot;
	int		i;

	i = 0;
	sign = 1;
	tot = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	if (str[i] == '\0')
		writer();
	notdigit(str);
	while (ft_isdigit(*str))
	{
		tot = tot * 10 + (*str - 48);
		str++;
	}
	if ((tot * sign) > 2147483647 || (tot * sign) < -2147483648)
		writer();
	return (tot * sign);
}

void	checkdouble(int ac, int *p)
{
	int	i;
	int	j;

	if (ac > 1)
	{
		i = 0;
		j = 0;
		while (i < ac - 1)
		{
			j = i + 1;
			while (j < ac)
			{
				if (p[i] == p[j])
					writer();
				j++;
			}
			i++;
		}
	}
}
