/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:42:44 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/04 09:32:09 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

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
        if (!list->down)
            v.arg[v.i++] = change(list, myenv);
        else
        {
            v.tmp = list;
            while (v.tmp)
            {
                v.str = ft_strjoin(v.str, change(v.tmp, myenv));
                v.tmp = v.tmp->down;
            }
            v.arg[v.i++] = v.str;
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
    paths = ft_split(path, ':');
    while (paths[++i])
    {
        new_arg = ft_strjoin_sp(paths[i], arg, '/');
        // printf("new arg = %s\n", new_arg);
        if (!access(new_arg, X_OK))
            return (new_arg);
    }
    return (paths[0]);
}

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

void exec_cmd(t_ast **ast, t_env *myenv)
{
    pid_t pid;
    t_env *tmp;
    char **arg;
    char **env;
    int stat;

    arg = trans_list(((t_command *)*ast)->list, myenv);
    if (builting(myenv, arg))
        return ;
    tmp = ft_lstchr(myenv, "PATH");
    if (!tmp)
        return (ft_putendl_fd("error", 2));
    env = trans_myenv(myenv);
    pid = fork();
    if  (pid == -1)
        return ;
    if (!pid)
    {
        execve(valid_path(arg[0], tmp->value), arg, env);
        perror(arg[0]); //!!!!
        exit(127);
    }
    waitpid(pid, &stat, WUNTRACED);
    exit_status(myenv, WEXITSTATUS(stat));
    // printf("\n=== >%d\n", WEXITSTATUS(stat));
    // int i = -1;
    // while (arg[++i])
    //     printf("arg[%d] =  %s\n",i, arg[i]);
    
}
void exit_status(t_env *myenv ,int status)
{
    t_env *find;

    find = ft_lstchr(myenv, "?");
    find->value = ft_itoa(status);
}