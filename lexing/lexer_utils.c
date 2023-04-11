/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 08:40:34 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/11 08:44:20 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "minishell.h"

char	*getword(char *str, int *index)
{
	int	i;
	int	j;

	i = *index;
	j = i;
	while (str[i] && !ft_strchr("\"\'|<>&() \t", str[i]))
		i++;
	return (*index = i - 1, ft_substr(str, j, i - j));
}

char	*getq(char *str, int *index, char c)
{
	int	i;
	int	j;

	i = *index;
	j = i;
	while (str[i] && str[i] != c)
		i++;
	if (!str[i])
		return (*index = i - 1, ft_substr(str, j, i - j));
	return (*index = i - 1, ft_substr(str, j, i - j));
}

int	getflag(char c, int flag)
{
	char	*str;
	int		i;

	i = -1;
	str = "\"\'|<>()";
	while (str[++i])
		if (str[i] == c)
			break ;
	if (c == '&' && !flag)
		return (0);
	else if (c == '&' && flag)
		return (9);
	(flag) && (i += 7);
	return (i + 1);
}

int	allspace(int i, char *c)
{
	while (c[i] && c[i] == ' ')
		i++;
	if (c[i])
		return (0);
	else
		return (1);
}
