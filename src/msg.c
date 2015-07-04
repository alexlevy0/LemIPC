/*
** msg.c for lemipc in /home/camill_n/rendu/PSU_2014_lemipc
**
** Made by camill_n
** Login   <camill_n@epitech.net>
**
** Started on  Fri Mar  6 11:41:27 2015
** Last update Sun Mar  8 14:18:33 2015 
*/

#include "lemipc.h"

void	init_msg(t_data *data)
{
  data->msg_ident = msgget(data->key, 0);
}

void	delete_msg(t_data *data)
{
  msgctl(data->msg_ident, IPC_RMID, 0);
}

void	send_msg(t_data *data, int pos)
{
  t_msg	msg;

  msg.typeMessage = data->team_id;
  msg.pos = pos;
  msgsnd(data->msg_ident, &msg, sizeof(t_msg), 0);
}

int	rcv_msg(t_data *data)
{
  t_msg	msg;

  msg.typeMessage = data->team_id;
  msgrcv(data->msg_ident, &msg, sizeof(t_msg), data->team_id, IPC_NOWAIT);
  if (errno == ENOMSG)
    return (-1);
  return (msg.pos);
}
