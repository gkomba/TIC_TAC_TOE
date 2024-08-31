#ifndef TIC_TAC_TOE_H
# define TIC_TAC_TOE_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <time.h>

typedef struct s_vars 
{
    bool    turno;
    char    **camp;
    char    *player1;
    char    *player2;
} t_vars;

void    ft_win(t_vars *vars, char c);
void    render(int nbr, t_vars *vars);
void	ft_free_matriz(char **arr);

#endif