/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 06:42:11 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/11 08:53:08 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_tokens(t_token *node)
{
	char	*str;

	str = NULL;
	while (node)
	{
		str = ft_strjoin(str, node->token);
		node = node->down;
	}
	return (str);
}

void	param_herdoc(int signum)
{
	(void)signum;
	close(STDIN_FILENO);
}

void	signal_herdoc(int fd[2])
{
	int	fdt;

	fdt = open(ttyname(STDERR_FILENO), O_RDONLY);
	if (fdt == -1)
		return (close_pipe(fd), ft_putendl_fd("open sig_her", 2));
	close_pipe(fd);
}

int	heredoc(char *lim)
{
	int		fd[2];
	int		len;
	char	*buff;

	if (!lim || pipe(fd) == -1)
		return (-1);
	len = ft_strlen(lim);
	signal(SIGINT, param_herdoc);
	while (isatty(STDIN_FILENO))
	{
		buff = readline("> ");
		if (!buff || !ft_memcmp(lim, buff, len + 1))
		{
			free(buff);
			break ;
		}
		write(fd[1], buff, ft_strlen(buff));
		write(fd[1], "\n", 1);
		free(buff);
	}
	signal(SIGINT, param_sig);
	if (!isatty(STDIN_FILENO))
		return (signal_herdoc(fd), set_statu(1), 0);
	return (close(fd[1]), fd[0]);
}
