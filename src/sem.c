/*
** sem.c for lemipc in /home/camill_n/rendu/PSU_2014_lemipc
**
** Made by camill_n
** Login   <camill_n@epitech.net>
**
** Started on  Fri Mar  6 11:02:53 2015
** Last update Fri Mar  6 11:26:04 2015 
*/

#include "lemipc.h"

void	init_sem(t_data *data)
{
  struct sembuf  op;

  op.sem_num = 0;
  op.sem_op = 1;
  /* Ecriture/Lecture pour moi et les gens de mon groupe */
  /* Rien pour les autres ! */
  data->sem_ident = semget(data->key, 1, IPC_CREAT | IPC_EXCL | 0660);
  semop(data->sem_ident, &op, 1);
}

void	lock_sem(t_data *data)
{
  struct sembuf  op;

  op.sem_num = 0;
  op.sem_op = -1;
  semop(data->sem_ident, &op, 1);
}

void	unlock_sem(t_data *data)
{
  struct sembuf  op;

  op.sem_num = 0;
  op.sem_op = 1;
  semop(data->sem_ident, &op, 1);
}

void	delete_sem(t_data *data)
{
  semctl(data->sem_ident, 0, IPC_RMID);
}
