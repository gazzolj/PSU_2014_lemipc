/*
** action.c for lemipc in /home/verove_j/rendu/PSU_2014_lemipc
** 
** Made by Jordan Verove
** Login   <verove_j@epitech.net>
** 
** Started on  Thu Mar  5 16:36:46 2015 Jordan Verove
** Last update Sat Mar  7 15:54:02 2015 Jordan Verove
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "lemipc.h"

int		check_if_last(char *map)
{
  int		i;

  i = 0;
  while (map[i] != '\0')
    {
      if (map[i] != '.')
	return (-1);
      i = i + 1;
    }
  return (1);
}

int		check_if_dead(char *arround)
{
  int		i;
  int		j;
  char		c;

  i = 0;
  j = 0;
  while (j != 8)
    {
      c = arround[j];
      while (i != 8)
        {
          if (c == arround[i] && i != j&& c !='.')
            return (1);
          i = i + 1;
        }
      j = j + 1;
      i = 0;
    }
  return (0);
}

char		*check_arroud2(char *arroud, int pos, char *map)
{
  if ((pos + 1) <= 899 && (pos % 29) != 0)
    arroud[4] = map[pos + 1];
  else
    arroud[4] = '.';
  if ((pos + 29) < 899 && ((pos + 29) % 29) != 0)
    arroud[5] = map[pos + 29];
  else
    arroud[5] = '.';
  if ((pos + 30) <= 899)
    arroud[6] = map[pos + 30];
  else
    arroud[6] = '.';
  if ((pos + 31) < 899 && (pos % 29) != 0)
    arroud[7] = map[pos + 31];
  else
    arroud[7] = '.';
  arroud[8] = '\0';
  return (arroud);
}

char		*check_arroud1(char *map, int pos)
{
  char		*arroud;

  if ((arroud = malloc(9 * sizeof(char))) == NULL)
    return (NULL);
  if ((pos - 31) >= 0)
    arroud[0] = map[pos - 31];
  else
    arroud[0] = '.';
  if ((pos - 30) >= 0)
    arroud[1] = map[pos - 30];
  else
    arroud[1] = '.';
  if ((pos - 29) > 0 && (pos % 29) != 0)
    arroud[2] = map[pos - 29];
  else
    arroud[2] = '.';
  if ((pos - 1) >= 0 && ((pos - 1) % 29) != 0)
    arroud[3] = map[pos - 1];
  else
    arroud[3] = '.';
  arroud = check_arroud2(arroud, pos, map);
  return (arroud);
}

void		init_function(int (*tab[])(char *map, char team, int pos))
{
  tab[0] = &move_left;
  tab[1] = &move_right;
  tab[2] = &move_up;
  tab[3] = &move_down;
}

int		do_action(char *map, char team, int pos)
{
  int		(*tab[4])(char *map, char team, int pos);
  int		rand_value;

  print_map(map);
  init_function(tab);
  rand_value = rand() % 4;
  pos = (*tab[rand_value])(map, team, pos);
  if (check_if_dead(check_arroud1(map, pos)) == 1)
    {
      map[pos] = '.';
      return (-1);
    }
  return (pos);
}
