#include "tic_tac_toe.h"

static int choose_turn(void)
{
    int i;
    int random;

    srand(time(NULL));
    i = 4;
    while (i-- != 0)
        random = rand() % 2;
    return (random);
}

int main(int argc, char **argv)
{
    int     i;
    int     j;
    int     counter;
    t_vars vars;

    (void)argc;
    if (argv[1] && argv[2])
    {
        vars.player1 = argv[1];
        vars.player2 = argv[2];
    }
    if (!argv[1])
    {
        vars.player1 = "P1";
        vars.player2 = "P2";
    }
    else if (!argv[2] && argv[1])
    {
        vars.player1 = argv[1];
        vars.player2 = "P2";
    }
    vars.turno = choose_turn();
    vars.camp = (char **)malloc(sizeof(char *) * 4);
    i = -1;
    while (++i < 3)
    {
        vars.camp[i] = malloc(4);
        j = -1;
        while (++j < 3)
            vars.camp[i][j] = '-';
        vars.camp[i][j] = '\0';
    }
    i = -1;
    while (vars.camp[++i])
        printf("%s\n", vars.camp[i]);
    while (1)
    {
        counter = system("./read.sh");
        render(counter, &vars);
    }
}