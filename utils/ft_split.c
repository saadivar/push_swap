/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:49:43 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/01/07 00:46:06 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

size_t	ft_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

char	**free_strs(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		strs[i] = NULL;
		i++;
	}
	free(strs);
	strs = NULL;
	return (strs);
}

size_t	get_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	size_t	index;
	char	**strs;

	if (!s)
		return (NULL);
	strs = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!strs)
		return (NULL);
	index = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			strs[index++] = ft_substr(s, 0, get_len(s, c));
			if (!strs[index - 1])
				return (free_strs(strs));
			s += get_len(s, c);
		}
	}
	strs[index] = 0;
	return (strs);
}
