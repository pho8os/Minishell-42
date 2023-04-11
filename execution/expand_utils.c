/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 08:41:34 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/11 08:42:28 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*handle_non_valid_variable(char *str, int *i)
{
	int		j;
	char	*var;

	j = *i + 1;
	while (str[j] && str[j] != '$')
		j++;
	var = ft_substr(str, *i, j - *i);
	*i = j;
	return (ft_strdup(var));
}

char	*handle_non_variable(char *str, int *i)
{
	int	j;

	j = *i;
	while (str[*i] && str[*i] != '$')
		(*i)++;
	return (ft_substr(str, j, *i - j));
}

char	*handle_variable(char *str, t_env *env, int *i)
{
	char	*p;
	int		j;

	j = *i + 1;
	if (str[j] && (str[j] == '_' || ft_isalpha(str[j])))
		p = handle_env_variable(str, env, i, j);
	else if (str[j] == '?')
	{
		*i += 2;
		p = ft_itoa(g_stat);
	}
	else
		p = handle_non_valid_variable(str, i);
	return (p);
}

char	*handle_env_variable(char *str, t_env *env, int *i, int j)
{
	char	*var;

	while (str[j] && (str[j] == '_' || ft_isalnum(str[j])))
		j++;
	var = ft_substr(str, *i + 1, j - *i - 1);
	*i = j;
	return (ft_strdup(getv(var, env)));
}
