/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:42:44 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/10 04:55:42 by yettabaa         ###   ########.fr       */
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
    env = gc(sizeof(char *) * (len + 1), 1, 0);
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

    expand_change(&list, myenv);
    wildcard_change(&list);
    v.arg = gc(sizeof(char *) * (size_token(list) + 1), 1, 0);
    v.i = 0;
    v.str = NULL;
    while (list)
    {
        (!list->down) && (v.arg[v.i++] = list->token);
        if (list->down)
        {
            v.tmp = list;
            while (v.tmp)
            {
                v.str = ft_strjoin(v.str, v.tmp->token);
                // v.str = ft_strjoin(v.str, expand_prime(v.tmp->token, myenv));
                v.tmp = v.tmp->down;
            }
            v.arg[v.i++] = v.str;
            v.str = NULL;
        }
        list = list->next;
    }
    return (v.arg[v.i] = 0, v.arg);
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
    pid_t pid;
    t_env *tmp;
    int stat;

    arg = trans_list(((t_command *)ast)->list, myenv);
    if (builting(myenv, arg) || !*arg[0]) //if commad not builing then check empty command
        return ;
    tmp = ft_lstchr(myenv, "PATH");
    if (!tmp)
        return (fd_printf(2, "%s: No such file or directory\n", arg[0]));
    pid = fork();
    if  (pid == -1)
        return (perror("fork"));
    if (!pid)
    {
        signal(SIGQUIT, SIG_DFL);
        signal(SIGINT, SIG_DFL);
        execve(valid_path(arg[0], tmp->value), arg, trans_myenv(myenv));
        fd_printf(2, "Exec : command not found: %s\n", arg[0]);
        exit(127);
    }
    waitpid(pid, &stat, WUNTRACED);
    exit_status(stat);
}
