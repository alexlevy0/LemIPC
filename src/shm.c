/*
** shm.c for lemipc in /home/camill_n/rendu/PSU_2014_lemipc
**
** Made by camill_n
** Login   <camill_n@epitech.net>
**
** Started on  Wed Mar  4 16:56:03 2015
** Last update Fri Mar  6 17:00:07 2015 
*/

#include "lemipc.h"

void	init_shm(t_data *data)
{
  if ((data->shm_ident = shmget(data->key, sizeof(t_map), 0600)) == -1)
    {
      printf("Creation shm\n");
      data->shm_ident = shmget(data->key, sizeof(t_map),
			       IPC_CREAT | IPC_EXCL | 0666);
      data->primary = 1;
    }
  else
    {
      printf("Recup shm\n");
      data->primary = 0;
    }
  if (data->shm_ident == -1)
    {
      printf("Memory shared cannot be load\n");
      exit(EXIT_FAILURE);
    }
  data->primary_end = 0;
  data->map = (t_map *)(shmat(data->shm_ident, 0, 0));
}

void	delete_shm(t_data *data)
{
  printf("Destruction of shm\n");
  shmctl(data->shm_ident, IPC_RMID, 0);
}

void	detach_shm(t_data *data)
{
  printf("Detachement of shm\n");
  shmdt(data->map);
}
