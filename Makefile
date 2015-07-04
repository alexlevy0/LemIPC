##
## Makefile for lemipc in /home/camill_n/rendu/PSU_2014_lemipc
##
## Made by Nicolas Camilli
## Login   <camill_n@epitech.net>
##
## Started on  Thu Feb 26 15:40:00 2015 Nicolas Camilli
## Last update Sun Mar  8 20:03:21 2015 LEVY Alexandre
##

SRCS	= src/main.c \
	  src/keys.c \
	  src/shm.c \
	  src/game.c \
	  src/map.c \
	  src/sem.c \
	  src/move.c \
	  src/ia.c \
	  src/msg.c \
	  src/sdl.c \

RM	= rm -f

NAME	= lemipc

CC	= gcc -g3 -lSDL -lSDL_mixer

CFLAGS	= -I include/

OBJS	= $(SRCS:.c=.o)

all:	 $(NAME)

$(NAME): $(OBJS)
	  $(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

