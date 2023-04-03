/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:09:17 by absaid            #+#    #+#             */
/*   Updated: 2023/04/03 09:52:04 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

t_ast *parse_cmd(t_token **tok)
{
    t_ast *ast;
    t_token *tmp;
    
    if (!*tok)
        return(NULL);
    if ((*tok)->type == END)
        return(NULL);
    if ((*tok)->type == OPAR)
        return (parse_sub(tok));   
    if ((*tok)->type == WORD)
    {
        
        // printf("==> %u\n", (*tok)->type);
        tmp = *tok;
        while ((*tok)->type == WORD && (*tok)->type != END)
            *tok = (*tok)->next;
        ast = new_cmd(tmp);
        return(ast);
    }
    return(parse_oper(tok));
}
void add_baa(t_ast *tree, t_ast *addin)
{
    if (tree == NULL)
        return ;
	while (((t_redr *)tree)->trdr)
		tree = ((t_redr *)tree)->trdr;
	((t_redr *)tree)->trdr = addin;
}
t_ast *redire_info(t_token **tok)
{
    t_ast *reder;
       
    reder = new_reder(); // handl syntax error
    ((t_redr *)reder)->typerdre = (*tok)->type;
    *tok = (*tok)->next;
    ((t_redr *)reder)->arg = *tok; // join and change in char * in heder
    *tok = (*tok)->next;
    return (reder);
}
void addb_list(t_ast *ast, t_token **tok) // checking
{
    t_token *find;

    find = lasttok(((t_command *)ast)->list);
    find->next = ft_newtoken(0 ,NULL, 0, 0);
    find = find->next;
    find->type = (*tok)->type;
    find->hdoc = (*tok)->hdoc;
    find->expand = (*tok)->expand;
    find->token = (*tok)->token;
    find->down = (*tok)->down;
    find->prev = (*tok)->prev;
    find->next = NULL;
    *tok = (*tok)->next;
    
}
t_ast *parse_reder(t_token **tok)
{
    t_ast *ast;
    t_ast *reder;

    
    if ((*tok)->type != RIN || (*tok)->type != ROUT || (*tok)->type != HEREDOC || (*tok)->type != APPEND) // not == word in case of subshell
        ast = parse_cmd(tok);
    if ((*tok)->type == RIN || (*tok)->type == ROUT || (*tok)->type == HEREDOC || (*tok)->type == APPEND)
    {
        reder = redire_info(tok);
        printf("zb %d\n", reder->type);
        while ((*tok)->type != AND && (*tok)->type != OR && (*tok)->type != PIPE && (*tok)->type != END)
        {
            if ((*tok)->type == RIN || (*tok)->type == ROUT || (*tok)->type == HEREDOC || (*tok)->type == APPEND)
                add_baa(reder, redire_info(tok));
            else if ((*tok)->type == WORD && !ast)
                ast = parse_cmd(tok);
            else    
                addb_list(ast, tok);
        }
        add_baa(reder, ast);
        return(reder);
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
    // ast = parse_sub(tok);
    while ((*tok)->type == PIPE)
    {
        if ((*tok)->type == PIPE)
        {
            ast = new_oper((*tok)->type, ast, NULL, (*tok)->token);
            *tok = (*tok)->next;
        }
        ((t_operator *)ast)->right = parse_reder(tok);
        // ((t_operator *)ast)->right = parse_sub(tok);
    }
    return(ast);
}

t_ast *parse_oper(t_token **tok)
{
    t_ast *ast;
    
    ast = parse_pipe(tok);
    while ((*tok)->type == AND || (*tok)->type == OR)
    {
        if ((*tok)->type == AND || (*tok)->type == OR)
        {
            ast = new_oper((*tok)->type, ast, NULL, (*tok)->token);
            *tok = (*tok)->next;
        }
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

