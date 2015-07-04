/*
** game.c for lemipc in /home/camill_n/rendu/PSU_2014_lemipc
**
** Made by camill_n
** Login   <camill_n@epitech.net>
**
** Started on  Wed Mar  4 20:03:10 2015
** Last update Sun Mar  8 12:38:42 2015 
*/

#include "lemipc.h"

int	is_trap(t_data *data)
{
  int	cpt[5];

  bzero(cpt, 5 * sizeof(int));
  if (POS - 1 >= 0 && TAB[POS - 1] && TAB[POS - 1] != data->team_id)
    ++cpt[TAB[POS - 1]];
  if (POS + 1 < SIZE && TAB[POS + 1] && TAB[POS + 1] != data->team_id)
    ++cpt[TAB[POS + 1]];
  if (POS - MAP_WIDTH >= 0 && TAB[POS - MAP_WIDTH] &&
      TAB[POS - MAP_WIDTH] != data->team_id)
    ++cpt[TAB[POS - MAP_WIDTH]];
  if (POS + MAP_WIDTH < SIZE && TAB[POS + MAP_WIDTH] &&
      TAB[POS + MAP_WIDTH] != data->team_id)
    ++cpt[TAB[POS + MAP_WIDTH]];
  return (cpt[1] > 1 || cpt[2] > 1 || cpt[3] > 1 || cpt[4] > 1);
}

void		is_finish(t_data *data)
{
  unsigned int	cpt[NB_TEAM + 1];
  unsigned int	i;
  unsigned int	cond;

  cond = 0;
  i = 1;
  map_stat(data, cpt);
  while (i < NB_TEAM + 1)
    {
      if (cpt[i] > 1)
	cond |= 0x01;
      else if (cpt[i] == 1)
	cond |= 0x02;
      ++i;
    }
  if (cond != 3)
    {
      data->run = 0;
      data->primary_end = 1;
    }
}

void	display_map(t_data *data)
{
  unsigned int	i;
  unsigned int	size;

  i = 0;
  size = MAP_WIDTH * MAP_HEIGHT;
  system("clear");
  printf("\r");
  while (i < size)
    {
      if (i && !(i % MAP_WIDTH))
	printf("\n");
      if (data->run)
	printf("%d ", data->map->tab[i], i);
      ++i;
    }
}

void	loop(t_data *data)
{
  while (data->run || (data->primary && !data->primary_end))
    {
      if (data->primary)
	display_map(data);
      if (data->run)
	{
	  if (is_trap(data))
	    data->run = 0;
	  move(data, data->pos + 1);
	  choose_dep(data);
	}
      usleep(100000);
      is_finish(data);
    }
  if (data->map->tab[data->pos])
    data->map->tab[data->pos] = 0;
  --data->map->nb_gamer;

  delete_msg(data);
  detach_shm(data);
  if (data->primary)
    {
      delete_sem(data);
      delete_shm(data);
    }
}
