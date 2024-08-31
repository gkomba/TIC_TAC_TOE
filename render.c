#include "tic_tac_toe.h"

static void    ft_fill_the_houses(t_vars *vars, int y, int x, char c)
{
    vars->camp[y][x] = c;
    ft_win(vars, c);
    if (vars->turno == 0)
        vars->turno = 1;
    else
        vars->turno = 0;
}

void    render(int nbr, t_vars *vars)
{
    int     i;
    char    c;

    if (vars->turno == 0)
        c = 'x';
    else
        c = 'o';
    system("clear");
    if (nbr == 256 && vars->camp[0][0] == '-')
        ft_fill_the_houses(vars, 0, 0, c);
    else if (nbr == 512 && vars->camp[0][1] == '-')
        ft_fill_the_houses(vars, 0, 1, c);
    else if (nbr == 768 && vars->camp[0][2] == '-')
        ft_fill_the_houses(vars, 0, 2, c);
    else if (nbr == 1024 && vars->camp[1][0] == '-')
        ft_fill_the_houses(vars, 1, 0, c);
    else if (nbr == 1280 && vars->camp[1][1] == '-')
        ft_fill_the_houses(vars, 1, 1, c);
    else if (nbr == 1536 && vars->camp[1][2] == '-')
        ft_fill_the_houses(vars, 1, 2, c);
    else if (nbr == 1792 && vars->camp[2][0] == '-')
        ft_fill_the_houses(vars, 2, 0, c);
    else if (nbr == 2048 && vars->camp[2][1] == '-')
        ft_fill_the_houses(vars, 2, 1, c);
    else if (nbr == 2304 && vars->camp[2][2] == '-')
        ft_fill_the_houses(vars, 2, 2, c);
    else if (nbr == 0)
        exit(0);
    else
    {
        printf("CASA OCUPADA\nTRY AGAIN\n");
        sleep(1);
        system("clear");
    }
    i = -1;
    while (vars->camp[++i])
        printf("%s\n", vars->camp[i]);
}