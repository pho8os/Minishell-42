/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 06:42:11 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/07 06:38:28 by yettabaa         ###   ########.fr       */
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

int stdin_copy = -1;

void param_herd(int signum)
{
	(void) signum;
	stdin_copy = dup(STDIN_FILENO);
	close(STDIN_FILENO);
	// write(1, "\n", 1);
	// write(1, "l", 1);
	// exit(0);
	// rl_on_new_line();
	// rl_replace_line("", 0);
	// rl_redisplay();
}

int	heredoc(char *lim)
{
	int		fd[2];
	int		len;
	char	*buff;

	if (!lim || pipe(fd) == -1)
		return (-1);
	len = ft_strlen(lim);
	signal(SIGINT, param_herd);
	while (1)
	{
		buff = readline("> ");
		if (!buff || !ft_memcmp(lim, buff, len + 1))
			break ;
		write(fd[1], buff, ft_strlen(buff));
		write(fd[1], "\n", 1);
		free(buff);
	}
	if (stdin_copy != -1)
	{
		dup2(stdin_copy, STDIN_FILENO);
		close(stdin_copy);
		stdin_copy = -1;
		return (close(fd[1]), close(fd[0]), -1);
	}
	return (close(fd[1]), fd[0]);
}
