/*
** move.c for lemipc in /home/camill_n/rendu/PSU_2014_lemipc
**
** Made by camill_n
** Login   <camill_n@epitech.net>
**
** Started on  Fri Mar  6 00:53:05 2015
** Last update Fri Mar  6 11:19:33 2015 
*/

#include "lemipc.h"

void	move(t_data *data, int pos)
{
  lock_sem(data);
  pos %= SIZE;
  if (!TAB[pos])
    {
      TAB[data->pos] = 0;
      TAB[pos] = data->team_id;
      data->pos = pos;
    }
  unlock_sem(data);
}

void	pos_argv(t_data *data, int ac, char **av)
{
  int	i;
  int	x;
  int	y;

  i = 0;
  x = data->pos % MAP_WIDTH;
  y = data->pos / MAP_WIDTH;
  while (i < ac)
    {
      !strcmp(av[i], "-x") && i != ac- 1 ? x = atoi(av[i + 1]) : 0;
      !strcmp(av[i], "-y") && i != ac- 1 ? y = atoi(av[i + 1]) : 0;
      ++i;
    }
  move(data, x + (y * MAP_WIDTH));
}
