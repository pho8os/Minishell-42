/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:32:56 by absaid            #+#    #+#             */
/*   Updated: 2023/03/13 02:48:11 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "lexer.h"
# include "parser.h"
# include "executor.h"
# include "builtins.h"
# include "../Libft-42/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <limits.h>

// typedef struct s_list
// {
// 	char			*variable;
// 	char			*value;
// 	struct s_list	*next;
// }	t_env;

// typedef struct s_minishell
// {
//     t_env *myenv;
    
// }t_minishell;

// extern t_minishell g_minishell;
void dupenv(char **env, t_env **myenv, t_env **myexp);
#endif