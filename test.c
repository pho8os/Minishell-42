

#include "readline/readline.h"


int main(int argc, char const *argv[])
{
    rl_replace_line("New command", 0);
    return 0;
}
