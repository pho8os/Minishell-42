/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:42:44 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/06 09:59:18 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

char **trans_myenv(t_env *myenv)
{
    int i;
    int len;
    char **env;
    
    i = 0;
    len = ft_lstsize(myenv);
    env = malloc(sizeof(char *) * (len + 1));
    if (!env)
        return (NULL);
    env[len] = 0;
    while (myenv)
    {
        (myenv->print) && (env[i++] = ft_strjoin_sp(myenv->variable, myenv->value, '='));
        myenv = myenv->next;
    }
    return (env);
}

char **trans_list(t_token *list, t_env *myenv)
{
    t_vartrans_list v;
    
    v.arg = malloc(sizeof(char *) * (size_token(list) + 1));
    if (!v.arg)
        return (NULL);
    v.i = 0;
    v.str = NULL;
    while (list)
    {
        (!list->down) && (v.arg[v.i++] = change(list, myenv));
        if (list->down)
        {
            v.tmp = list;
            while (v.tmp)
            {
                v.str = ft_strjoin(v.str, change(v.tmp, myenv));
                v.tmp = v.tmp->down;
            }
            v.arg[v.i++] = v.str;
            v.str = NULL;
        }
        list = list->next;
    }
    return (v.arg[v.i] = 0, v.arg);
}

char **test_dzb(char **arg) // !!!
{
    int i = -1;
    char *str = NULL;
    
    while(arg[++i])
        str = ft_strjoin_sp(str, arg[i], ' ');
    return (ft_split(str, ' '));    
}

char *valid_path(char *arg, char *path)
{
    int i;
    char *new_arg;
    char **paths;
    
    i = -1;
    if (!access(arg, X_OK))
        return (arg);
    paths = ft_split(path, ':');
    while (paths[++i])
    {
        new_arg = ft_strjoin_sp(paths[i], arg, '/');
        if (!access(new_arg, X_OK))
            return (new_arg);
    }
    return (paths[0]);
}

void exec_cmd(t_ast *ast, t_env *myenv)
{
    char **arg;
    char **argzb;
    pid_t pid;
    t_env *tmp;
    int stat;
    // char **env = trans_myenv(myenv);

    arg = trans_list(((t_command *)ast)->list, myenv);
    argzb = test_dzb(arg);
    // int i = -1;
    // while (env[++i])
    //     printf("env[%d] =  %s\n",i, env[i]);
    if (builting(myenv, arg, argzb))
        return ;
    tmp = ft_lstchr(myenv, "PATH");
    if (!tmp)
        return (ft_putendl_fd("error", 2));
    pid = fork();
    if  (pid == -1)
        return ;
    if (!pid)
    {
        execve(valid_path(argzb[0], tmp->value), argzb, trans_myenv(myenv));
        perror(argzb[0]); //!!!!
        exit(127);
    }
    waitpid(pid, &stat, WUNTRACED);
    exit_status(myenv, WEXITSTATUS(stat));
    // printf("\n=== >%d\n", WEXITSTATUS(stat));
    
}
