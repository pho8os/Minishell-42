/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 00:51:54 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/07 01:53:30 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int addback_redir(t_ast *tree, t_ast *addin)
{
    if (!addin || !tree)
        return(0) ;
	while (((t_redir *)tree)->trdr)
		tree = ((t_redir *)tree)->trdr;
	((t_redir *)tree)->trdr = addin;
    return (1);
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

t_ast *redire_info(t_token **tok)
{
    int type;
    t_ast *redir;
       
    if ((*tok)->type != RIN && (*tok)->type != ROUT && (*tok)->type != HEREDOC && (*tok)->type != APPEND)
        return(NULL);
    type = (*tok)->type;   
    redir = new_reder(); // handl syntax error
    ((t_redir *)redir)->typeredir = type;
    ((t_redir *)redir)->flags = O_RDONLY;
    if(type == ROUT || type == APPEND)
        ((t_redir *)redir)->flags = O_CREAT | O_WRONLY | ((type == ROUT) * O_TRUNC + !(type == RIN) * O_APPEND);
    *tok = (*tok)->next;
    if ((*tok)->type != WORD)
        return (NULL);
    ((t_redir *)redir)->tok = *tok; // join and change in char * in heder
    ((t_redir *)redir)->arg = join_tokens(*tok); // join and change in char * in heder
    (type == HEREDOC) && (((t_redir *)redir)->fd_in = heredoc(join_tokens(*tok)));    
    *tok = (*tok)->next;
    return (redir);
}