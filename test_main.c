#include "includes/minishell.h"

// int main()
// {
//     char pwd[PATH_MAX];
//     getcwd(pwd, PATH_MAX);
//     chdir("cd");
//     getcwd(pwd, PATH_MAX);
//     // char *str;
//     // str = getenv("PATH");
//     printf("%s\n", pwd);
// }
int main()
{
    t_env *head;

    head = NULL;
    addbenv (&head, newenv(ft_strdup("1"),ft_strdup("0")));
    addbenv (&head, newenv(ft_strdup("2"),ft_strdup("0")));
    // addbenv (&head, newenv(ft_strdup("3"),ft_strdup("0")));
    // addbenv (&head, newenv(ft_strdup("4"),ft_strdup("0")));

    delone_env(&head);
    printf("%s\n", head->variable);

}