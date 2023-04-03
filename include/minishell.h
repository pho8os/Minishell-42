/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:32:56 by absaid            #+#    #+#             */
/*   Updated: 2023/04/03 02:32:32 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../Libft-42/libft.h"
# include <stdbool.h>
# include <limits.h>
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
# include "filtrage.h"

// typedef struct s_glva
// {
// } t_glva;

// t_glva g_glva;
// extern t_glva g_glva;
#endif