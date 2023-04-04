/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:09:17 by absaid            #+#    #+#             */
/*   Updated: 2023/04/04 06:40:58 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

t_ast *parse_cmd(t_token **tok)
{
    t_ast *ast;
    t_token *tmp;
    
    if ((*tok)->type == END)
        return(NULL);
    if ((*tok)->type == OPAR)
        return (parse_sub(tok));   
    if ((*tok)->type == WORD)
    {
        tmp = *tok;
        while ((*tok)->type == WORD && (*tok)->type != END)
            *tok = (*tok)->next;
        return(ast = new_cmd(tmp), ast);
    }
    return(parse_oper(tok));
}

t_ast *parse_reder(t_token **tok)
{
    t_ast *ast;
    t_ast *reder;

    ast = NULL;
    if ((*tok)->type != RIN && (*tok)->type != ROUT && (*tok)->type != HEREDOC && (*tok)->type != APPEND) // not == word in case of subshell
        ast = parse_cmd(tok);
    if ((*tok)->type == RIN || (*tok)->type == ROUT || (*tok)->type == HEREDOC || (*tok)->type == APPEND)
    {
        reder = redire_info(tok);
        while ((*tok)->type != AND && (*tok)->type != OR && (*tok)->type != PIPE && (*tok)->type != END)
        {
            if ((*tok)->type == RIN || (*tok)->type == ROUT || (*tok)->type == HEREDOC || (*tok)->type == APPEND)
                add_baa(reder, redire_info(tok));
            else if ((*tok)->type == WORD && !ast)
                ast = parse_cmd(tok);
            else    
                addb_list(ast, tok);
        }
        return(add_baa(reder, ast), reder);
    }
    return (ast);
}

t_ast *parse_sub(t_token **tok)
{
    t_ast *ast;

    *tok = (*tok)->next;
    while ((*tok)->type != CPAR)
        ast = new_sub(parse_oper(tok));
    *tok = (*tok)->next;
    return (ast);
}

t_ast *parse_pipe(t_token **tok)
{
    t_ast *ast;

    ast = parse_reder(tok);
    while ((*tok)->type == PIPE)
    {
        ast = new_oper((*tok)->type, ast, NULL, (*tok)->token);
        *tok = (*tok)->next;
        ((t_operator *)ast)->right = parse_reder(tok);
    }
    return(ast);
}

t_ast *parse_oper(t_token **tok)
{
    t_ast *ast;
    
    ast = parse_pipe(tok);
    while ((*tok)->type == AND || (*tok)->type == OR)
    {
        ast = new_oper((*tok)->type, ast, NULL, (*tok)->token);
        *tok = (*tok)->next;
        ((t_operator *)ast)->right = parse_pipe(tok);
    }
    return(ast);
}

t_ast *parser(t_token **tok)
{
    if (!*tok)
        return (NULL);
    
    return (parse_oper(tok));
}

