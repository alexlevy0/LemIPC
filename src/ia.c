/*
** ia.c for lemipc in /home/camill_n/rendu/PSU_2014_lemipc
**
** Made by camill_n
** Login   <camill_n@epitech.net>
**
** Started on  Thu Mar  5 19:14:21 2015
** Last update Sun Mar  8 14:22:50 2015 
*/

#include "lemipc.h"

void	enemies_area(t_data *data, int range, int *cpt)
{
  int	pos;
  int	area_size;
  int	i;
  int	tot;
  int	size;

  bzero(cpt, (NB_TEAM + 1) * sizeof(int));
  pos = data->pos - (range * MAP_WIDTH) - range;
  (pos < 0) ? pos = 0 : 0;
  area_size = (pos << 1);
  !(pos % 2) ? ++pos : 0;
  i = 0;
  tot = (area_size * area_size);
  size = SIZE;
  while (i < tot)
    {
      if (i && !(i % area_size))
	pos += (MAP_WIDTH - range);
      if (pos == size)
	break;
      if (pos != data->pos && TAB[pos] > 0)
	++cpt[TAB[pos]];
      ++pos;
      ++i;
    }
}

void	choose_dep(t_data *data)
{
  int	cpt[NB_TEAM + 1];
  char	dst;
  int	pos;

  enemies_area(data, 1, cpt);

  if ((pos = rcv_msg(data)) > -1)
    pos = (data->pos - pos) / ABS(data->pos - pos);
  else
    {
      if (cpt[data->team_id] < 4)
	send_msg(data, data->pos);
      else
	{
	  dst = rand() % 3;
	  (dst == 0) ? (pos = data->pos + 1) : 0;
	  (dst == 1) ? (pos = data->pos - 1) : 0;
	  (dst == 2) ? (pos = data->pos + MAP_WIDTH) : 0;
	  (dst == 3) ? (pos = data->pos - MAP_WIDTH) : 0;
	}
      printf("1: %d\n", cpt[1]);
    }
  move(data, pos);
}
