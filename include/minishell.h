/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:32:56 by absaid            #+#    #+#             */
/*   Updated: 2023/04/11 08:58:55 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libgc/gc.h"
# include "../Libft-42/libft.h"
# include <dirent.h>
# include <stdbool.h>
# include <limits.h>
# include <fcntl.h>
# include <paths.h>
# include "lexer.h"
# include "parser.h"
# include "execution.h"
# include "builtins.h"
# include "readline/readline.h"
# include "readline/history.h"

int			g_stat;
typedef struct s_varibles
{
	char	*cmdl;
	t_ast	*ast;
	t_env	*myenv;
	t_token	*tok;
}			t_varibles;

#endif