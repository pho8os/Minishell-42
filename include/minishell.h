/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:32:56 by absaid            #+#    #+#             */
/*   Updated: 2023/04/04 07:04:42 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../Libft-42/libft.h"
# include <stdbool.h>
# include <limits.h>
# include <fcntl.h>
# include "lexer.h"
# include "parser.h"
# include "execution.h"
# include "builtins.h"
# include "readline/readline.h"
# include "readline/history.h"

typedef struct s_varibles
{
	t_ast *ast;
	t_env *myenv;
	t_token *tok;
}	t_varibles;

#endif