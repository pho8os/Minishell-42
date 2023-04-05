/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:09:17 by absaid            #+#    #+#             */
/*   Updated: 2023/04/05 09:40:51 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

t_ast *parse_cmd(t_token **tok)
{
    t_ast *ast;
    t_token *tmp;
    
    if ((*tok)->type == OPAR)
        return (parse_sub(tok));   
    if ((*tok)->type == WORD)
    {
        tmp = *tok;
        while ((*tok)->type == WORD && (*tok)->type != END)
            *tok = (*tok)->next;
        return(ast = new_cmd(tmp), ast);
    }
    if ((*tok)->type != WORD || (*tok)->type == END) // for syntax error
        return (NULL);
    return(parse_oper(tok));
}

t_ast *parse_redir(t_token **tok)
{
    t_ast *ast;
    t_ast *reder;

    ast = parse_cmd(tok); // no need to protection
    if ((*tok)->type == RIN || (*tok)->type == ROUT || (*tok)->type == HEREDOC || (*tok)->type == APPEND)
    {
        reder = redire_info(tok);
        while ((*tok)->type != AND && (*tok)->type != OR && (*tok)->type != PIPE && (*tok)->type != END)
        {
            if(!addback_redir(reder, redire_info(tok)))
                return(NULL);
            else if (ast && (*tok)->type == WORD)
                addb_list(ast, tok);
            else if (!ast  && (*tok)->type == WORD)
                ast = parse_cmd(tok);
        }
        return(addback_redir(reder, ast), reder);
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

    ast = parse_redir(tok);
    if (!ast)
        return (NULL);
    while ((*tok)->type == PIPE)
    {
        ast = new_oper((*tok)->type, ast, NULL);
        *tok = (*tok)->next;
        ((t_operator *)ast)->right = parse_redir(tok);
        if (!((t_operator *)ast)->right)
            return (NULL);
    }
    return(ast);
}

t_ast *parse_oper(t_token **tok)
{
    t_ast *ast;

    ast = parse_pipe(tok);
    if (!ast)
        return (NULL);
    while (*tok && ((*tok)->type == AND || (*tok)->type == OR))
    {
        ast = new_oper((*tok)->type, ast, NULL);
        *tok = (*tok)->next;
        ((t_operator *)ast)->right = parse_pipe(tok);
        if (!((t_operator *)ast)->right)
            return (NULL);
    }
    return(ast);
}

t_ast *parser(t_token **tok)
{
    t_ast *tree;
    
    if (!*tok || (*tok)->type == END) // hna ya phobos zamel
        return (NULL);
    tree = parse_oper(tok);
    if(!tree)
        printf("Syntax : Error unexpected token `%s'\n", (*tok)->token);
    return (tree);
}
