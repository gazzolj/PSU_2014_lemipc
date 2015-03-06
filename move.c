/*
** move.c for lemipc in /home/verove_j/rendu/PSU_2014_lemipc
** 
** Made by Jordan Verove
** Login   <verove_j@epitech.net>
** 
** Started on  Fri Mar  6 09:29:40 2015 Jordan Verove
** Last update Fri Mar  6 10:45:13 2015 Jordan Verove
*/

#include <stdio.h>

int		move_left(char *map, char team, int pos)
{
  printf("left\n");
  map[pos - 1] = team;
  map[pos] = '.';
  return (pos - 1);
}

int		move_right(char *map, char team, int pos)
{
  map[pos + 1] = team;
  map[pos] = '.';
  return (pos + 1);
}

int		move_up(char *map, char team, int pos)
{
  map[pos - 30] = team;
  map[pos] = '.';
  return (pos - 30);
}

int		move_down(char *map, char team, int pos)
{
  map[pos + 30] = team;
  map[pos] = '.';
  return (pos + 30);
}
