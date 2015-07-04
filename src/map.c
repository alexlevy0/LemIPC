/*
** map.c for lemipc in /home/camill_n/rendu/PSU_2014_lemipc
**
** Made by camill_n
** Login   <camill_n@epitech.net>
**
** Started on  Wed Mar  4 19:35:43 2015
** Last update Fri Mar  6 16:59:13 2015 
*/

#include "lemipc.h"

unsigned int	get_minor_team(unsigned int *cpt)
{
  unsigned int	i;
  unsigned int	id;

  i = 1;
  id = 0;
  while (i < NB_TEAM + 1)
    {
      if (!id || cpt[id] > cpt[i])
	    id = i;
      ++i;
    }
  return (id);
}

void	map_stat(t_data *data, unsigned int *cpt)
{
  unsigned int	i;
  unsigned int	size;
  int		id;

  i = 0;
  size = SIZE;
  bzero(cpt, (NB_TEAM + 1) * sizeof(unsigned int));
  while (i < SIZE)
    {
      ++cpt[TAB[i]];
      ++i;
    }
}

int	get_free_pos(t_data *data)
{
  unsigned int	i;
  unsigned int	size;

  i = 0;
  size = SIZE;
  while (i < size)
    {
      if (!data->map->tab[i])
	return (i);
      ++i;
    }
  return (-1);
}

void	init_res(t_data *data)
{
  printf("Init res !\n");
  data->map->width = MAP_WIDTH;
  data->map->height = MAP_HEIGHT;
  data->map->nb_gamer = 1;
  bzero(data->map->tab, (MAP_WIDTH * MAP_HEIGHT) * sizeof(char));
  data->id = 0;
  data->team_id = 1;
  data->pos = 0;
  data->map->tab[data->pos] = data->team_id;
  init_sem(data);
}

void	update_res(t_data *data)
{
  unsigned int	cpt[NB_TEAM + 1];

  data->id = data->map->nb_gamer;
  printf("Update res ! (nb_gamer: %d)\n", data->id + 1);
  ++data->map->nb_gamer;
  map_stat(data, cpt);
  data->team_id = get_minor_team(cpt);
  data->pos = get_free_pos(data);
  data->map->tab[data->pos] = data->team_id;
}
