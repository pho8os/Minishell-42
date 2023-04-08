/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:09:17 by absaid            #+#    #+#             */
/*   Updated: 2023/04/08 06:42:11 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

t_ast *parser(t_token **tok, t_env *myenv)
{
    t_ast *tree;
    
    if (!*tok || (*tok)->type == END) // hna ya phobos zamel
        return (NULL);
    tree = parse_oper(tok);
    if((!tree || (*tok)->type != END) && (*tok)->type != SIGHER)
    {
        exit_status(myenv, 258);
        fd_printf(2, "Syntax : Error unexpected token `%s'\n", (*tok)->token);
        return(NULL);
    }
    return (tree);
}
