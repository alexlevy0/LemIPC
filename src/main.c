/*
** main.c for myftp in /home/camill_n/rendu/PSU_2014_myftp/server
**
** Made by camill_n
** Login   <camill_n@epitech.net>
**
** Started on  Tue Mar  3 22:46:50 2015
** Last update Sun Mar  8 12:49:58 2015 
*/

#include "lemipc.h"

t_data		data;

void		del_res(int sig)
{
  data.run = 0;
}

int		main(int ac, char **av)
{
  show(&data);
  srand(time(NULL));
  init_key(&data, av[0]);
  init_shm(&data);
  init_msg(&data);
  signal(SIGINT, del_res);
  signal(SIGTERM, del_res);
  data.primary ? init_res(&data) : update_res(&data);
  data.run = 1;
  pos_argv(&data, ac, av);
  loop(&data);
  return (0);
}
