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
    printf("==>%s", getenv("HOME"));

}