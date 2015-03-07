/*
** move.c for lemipc in /home/verove_j/rendu/PSU_2014_lemipc
** 
** Made by Jordan Verove
** Login   <verove_j@epitech.net>
** 
** Started on  Fri Mar  6 09:29:40 2015 Jordan Verove
** Last update Sat Mar  7 14:41:47 2015 Jordan Verove
*/

#include <stdio.h>

int		move_left(char *map, char team, int pos)
{
  if (map[pos - 1] == '.' && ((pos - 1) % 29) != 0)
    {
      map[pos - 1] = team;
      map[pos] = '.';
      return (pos - 1);
    }
  return (pos);
}

int		move_right(char *map, char team, int pos)
{
  if (map[pos + 1] == '.' && ((pos + 1) % 30) != 0)
    {
      map[pos + 1] = team;
      map[pos] = '.';
      return (pos + 1);
    }
  return (pos);
}

int		move_up(char *map, char team, int pos)
{
  if (map[pos - 30] == '.' && (pos - 30) > 0)
    {
      map[pos - 30] = team;
      map[pos] = '.';
      return (pos - 30);
    }
  return (pos);
}

int		move_down(char *map, char team, int pos)
{
  if (map[pos + 30] == '.' && (pos + 30) < 900)
    {
      map[pos + 30] = team;
      map[pos] = '.';
      return (pos + 30);
    }
  return (pos);
}
