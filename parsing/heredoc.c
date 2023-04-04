/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 06:42:11 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/04 07:10:49 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void redir_fill(t_redir *node, int t)
// {
// 	node->type = t;
// 	node->fsrc = 0;
// 	node->fdst = 1;
// 	node->ofalgs = O_RDONLY;
// 	if(t == ROUT || t == APPEND)
// 		node->ofalgs = O_CREAT | O_WRONLY | ((t == ROUT) * O_TRUNC + !(t == RIN) * O_APPEND);
// 	(t == HEREDOC) && (node->fsrc = heredoc(join_tokens(node->file)));
// }

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