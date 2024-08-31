#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

typedef struct s_vars 
{
    bool    turno;
    char    **camp;
    char    *player1;
    char    *player2;
} t_vars;

void    ft_verify_horiontal(t_vars *vars, char c)
{
    if ((vars->camp[0][0] == c) && (vars->camp[0][1] == c) && (vars->camp[0][2] == c))
    {
        if (vars->turno == 0)
            printf("Jogador/a %s ganhou\n", vars->player1);
        else
            printf("Jogador/a %s ganhou\n", vars->player2);
        exit (0);
    }
     if ((vars->camp[1][0] == c) && (vars->camp[1][1] == c) && (vars->camp[1][2] == c))
    {
        if (vars->turno == 0)
            printf("Jogador/a %s ganhou\n", vars->player1);
        else
            printf("Jogador/a %s ganhou\n", vars->player2);
        exit (0);
    }
     if ((vars->camp[2][0] == c) && (vars->camp[2][1] == c) && (vars->camp[2][2] == c))
    {
        if (vars->turno == 0)
            printf("Jogador/a %s ganhou\n", vars->player1);
        else
            printf("Jogador/a %s ganhou\n", vars->player2);
        exit (0);
    }
}

void    ft_verify_vertical(t_vars *vars, char c)
{
    if ((vars->camp[0][0] == c) && (vars->camp[1][0] == c) && (vars->camp[2][0] == c))
    {
        if (vars->turno == 0)
            printf("Jogador/a %s ganhou\n", vars->player1);
        else
            printf("Jogador/a %s ganhou\n", vars->player2);
        exit (0);
    }
    if ((vars->camp[0][1] == c) && (vars->camp[1][1] == c) && (vars->camp[2][1] == c))
    {
        if (vars->turno == 0)
            printf("Jogador/a %s ganhou\n", vars->player1);
        else
            printf("Jogador/a %s ganhou\n", vars->player2);
        exit (0);
    }
    if ((vars->camp[0][2] == c) && (vars->camp[1][2] == c) && (vars->camp[2][2] == c))
    {
        if (vars->turno == 0)
            printf("Jogador/a %s ganhou\n", vars->player1);
        else
            printf("Jogador/a %s ganhou\n", vars->player2);
        exit (0);
    }
}

void    ft_verify_obliquo(t_vars *vars, char c)
{
    if ((vars->camp[0][0] == c) && (vars->camp[1][1] == c) && (vars->camp[2][2] == c))
    {
        if (vars->turno == 0)
            printf("Jogador/a %s ganhou\n", vars->player1);
        else
            printf("Jogador/a %s ganhou\n", vars->player2);
        exit (0);
    }
    if ((vars->camp[0][2] == c) && (vars->camp[1][1] == c) && (vars->camp[2][0] == c))
    {
        if (vars->turno == 0)
            printf("Jogador/a %s ganhou\n", vars->player1);
        else
            printf("Jogador/a %s ganhou\n", vars->player2);
        exit (0);
    }
}

void    ft_win(t_vars *vars, char c)
{
    ft_verify_horiontal(vars, c);
    ft_verify_vertical(vars, c);
    ft_verify_obliquo(vars, c);
}

void    ft_fill_the_houses(t_vars *vars, int y, int x, char c)
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

int choose_turn(void)
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
    char    *str;
    t_vars vars;

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