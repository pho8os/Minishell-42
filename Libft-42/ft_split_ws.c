/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ws.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 02:36:31 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/11 07:02:40 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\0');
}

static int	nb_word(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		while (*str && is_space(*str))
			str++;
		if (*str && !is_space(*str))
			i++;
		while (*str && !is_space(*str))
			str++;
	}
	return (i);
}

static int	str_lenw(char *str)
{
	int	i;

	i = 0;
	while (str[i] && !is_space(str[i]))
		i++;
	return (i);
}

char	**split_wc(char *str)
{
	int		i;
	int		j;
	char	**strs;

	strs = gc(sizeof(char *) * (nb_word(str) + 1), 1, 0);
	i = 0;
	while (*str)
	{
		while (*str && is_space(*str))
			str++;
		if (*str && !is_space(*str))
		{
			j = -1;
			strs[i] = gc(str_lenw(str) + 1, 1, 0);
			while (++j < str_lenw(str))
				strs[i][j] = str[j];
			strs[i][j] = '\0';
			i++;
		}
		while (*str && !is_space(*str))
			str++;
	}
	return (strs[i] = 0, strs);
}
