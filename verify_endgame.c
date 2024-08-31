#include "tic_tac_toe.h"

static void    ft_message(t_vars *vars)
{
    if (vars->turno == 0)
        printf("Jogador/a %s ganhou\n", vars->player1);
    else
        printf("Jogador/a %s ganhou\n", vars->player2);
    ft_free_matriz(vars->camp);
}

static void    ft_verify_horiontal(t_vars *vars, char c)
{
    if ((vars->camp[0][0] == c) && (vars->camp[0][1] == c) && (vars->camp[0][2] == c))
        ft_message(vars);
     if ((vars->camp[1][0] == c) && (vars->camp[1][1] == c) && (vars->camp[1][2] == c))
        ft_message(vars);
     if ((vars->camp[2][0] == c) && (vars->camp[2][1] == c) && (vars->camp[2][2] == c))
        ft_message(vars);
}

static void    ft_verify_vertical(t_vars *vars, char c)
{
    if ((vars->camp[0][0] == c) && (vars->camp[1][0] == c) && (vars->camp[2][0] == c))
        ft_message(vars);
    if ((vars->camp[0][1] == c) && (vars->camp[1][1] == c) && (vars->camp[2][1] == c))
        ft_message(vars);
    if ((vars->camp[0][2] == c) && (vars->camp[1][2] == c) && (vars->camp[2][2] == c))
        ft_message(vars);
}

static void    ft_verify_obliquo(t_vars *vars, char c)
{
    if ((vars->camp[0][0] == c) && (vars->camp[1][1] == c) && (vars->camp[2][2] == c))
        ft_message(vars);
    if ((vars->camp[0][2] == c) && (vars->camp[1][1] == c) && (vars->camp[2][0] == c))
        ft_message(vars);
}

void    ft_win(t_vars *vars, char c)
{
    ft_verify_horiontal(vars, c);
    ft_verify_vertical(vars, c);
    ft_verify_obliquo(vars, c);
}