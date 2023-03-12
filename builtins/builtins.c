/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:03:39 by yettabaa          #+#    #+#             */
/*   Updated: 2023/03/12 04:29:49 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

void test_builting(t_token *tok, t_env *myenv) //!!
{
    char **arg;
    int size_tok = lstsize_token(tok);
    int i = 0;

    arg = malloc(sizeof(char *) * (size_tok + 1));
    arg[size_tok] = 0;
    while (tok)
    {
        arg[i++] = tok->token;
        tok = tok->next;
    }
    if (ft_strncmp("cd", arg[0], 2) == 0)
        cd(arg[2]);
    else if (ft_strncmp("pwd", arg[0], 3) == 0)
        pwd();
    else if (ft_strncmp("env", arg[0], 3) == 0)
        print_env(myenv);
}

void print_env(t_env *envr)
{
    while (envr)
    {
        printf("%s=%s\n", envr->variable, envr->value);
        envr = envr->next;
    }
}

void cd_execute(const char *path)
{
    int ret;
    
    ret = chdir(path);
    if (ret != 0)
        perror(path);
}

void cd(const char *path)
{
    if (ft_strncmp("~", path, 1) == 0 || !path)
        cd_execute(getenv("HOME"));
    else    
        cd_execute(path);
}

void pwd(void)
{
    char *pwd;
    
    pwd = malloc(PATH_MAX);
    if (!pwd)
        return ;
    getcwd(pwd, PATH_MAX);
    ft_putendl_fd(pwd, STDOUT_FILENO);
}

// export

// void echo(char **)
// {
//     ft_putendl_fd
// }