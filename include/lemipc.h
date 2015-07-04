/*
** lemipc.h for lemipc in /home/camill_n/rendu/PSU_2014_lemipc
**
** Made by Nicolas Camilli
** Login   <camill_n@epitech.net>
**
** Started on  Thu Feb 26 15:46:21 2015 Nicolas Camilli
** Last update Sun Mar  8 14:22:20 2015 
*/

#ifndef LEMIPC_H_
# define LEMIPC_H_

# define MAP_WIDTH 8
# define MAP_HEIGHT 8
# define SIZE (MAP_HEIGHT * MAP_WIDTH)
# define NB_TEAM 4
# define ABS(s) (s > 0) ? s : -s
# define TAB data->map->tab
# define POS data->pos

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <errno.h>
#include <SDL/SDL.h>


typedef struct	s_map
{
  int		width;
  int		height;
  unsigned char	tab[MAP_WIDTH * MAP_HEIGHT];
  unsigned int	nb_gamer;
}		t_map;

typedef struct	s_msg
{
  long		typeMessage;
  int		pos;
}		t_msg;

typedef struct	s_data
{
  unsigned int	id;
  t_map		*map;
  key_t		key;
  int		shm_ident;
  int		sem_ident;
  int		msg_ident;
  unsigned char	team_id;
  int		pos;
  char		primary;
  char		primary_end;
  char		run;
}		t_data;

void	init_key(t_data *data, char *path);
void	init_shm(t_data *data);

void	display_map(t_data *data);
void	loop(t_data *data);
void	init_sem(t_data *data);
void	lock_sem(t_data *data);
void	unlock_sem(t_data *data);
void	delete_sem(t_data *data);
void	delete_shm(t_data *data);
void	detach_shm(t_data *data);
void	mode(t_data *data, int pos);
void	pos_argv(t_data *data, int ac, char **av);

void	init_msg(t_data *data);
void	delete_msg(t_data *data);
void	send_msg(t_data *data, int pos);
int	rdv_msg(t_data *data);
void	enemies_area(t_data *data, int range, int *cpt);
void	choose_dep(t_data  *data);

/*SDL*/
int     show(t_data *data);
void    pausee(void);


#endif
