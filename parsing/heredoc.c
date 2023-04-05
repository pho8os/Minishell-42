/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 06:42:11 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/05 06:10:11 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *join_tokens(t_token *node)
{
	char *str;
    
	str = NULL;
	while(node)
	{
		str = ft_strjoin(str, node->token);
		node = node->down;
	}
	return(str);
}

int	heredoc(char *delim)
{
	int	fd[2];
	int	len;
	char	*buff;

	if (!delim || pipe(fd) == -1)
		return (-1);
	len = ft_strlen(delim);
	while (1)
	{
		buff = readline(">");
		if (!buff || !ft_memcmp(delim, buff, len + 1))
			break ;
		write(fd[1], buff, ft_strlen(buff));
		write(fd[1], "\n", 1);
		free(buff);
	}
	return (close(fd[1]), fd[0]);
}