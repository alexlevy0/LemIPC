/*
** keys.c for lemipc in /home/camill_n/rendu/PSU_2014_lemipc
**
** Made by camill_n
** Login   <camill_n@epitech.net>
**
** Started on  Tue Mar  3 23:30:51 2015
** Last update Sun Mar  8 12:49:10 2015 
*/

#include "lemipc.h"

void	init_key(t_data *data, char *path)
{
  data->key = ftok(path, 0xF2);
  if (data->key == -1)
    {
      printf("Key generation failed.\n");
      exit(EXIT_FAILURE);
    }
  printf("Key generation success !\n");
}
