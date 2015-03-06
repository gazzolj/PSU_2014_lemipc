/*
** action.c for lemipc in /home/verove_j/rendu/PSU_2014_lemipc
** 
** Made by Jordan Verove
** Login   <verove_j@epitech.net>
** 
** Started on  Thu Mar  5 16:36:46 2015 Jordan Verove
** Last update Fri Mar  6 16:06:56 2015 Jordan Verove
*/

#include <unistd.h>
#include <stdio.h>

char		*check_if_dead(char *map, int pos, char team)
{
  char		arroud[8];

  if ((pos - 31) > 0)
    arroud[0] = map[pos - 31];
  
  arroud[1] = map[pos - 30];
  arroud[2] = map[pos - 29];
}

int		do_action(char *map, char team, int pos)
{
  print_map(map);
  pos = move_left(map, team + 48, pos);
  print_map(map);
  sleep(1);
  pos = move_up(map, team + 48, pos);
  print_map(map);
  sleep(1);
  pos = move_right(map, team + 48, pos);
  print_map(map);
  sleep(1);
  pos = move_down(map, team + 48, pos); 
  print_map(map);
  sleep(1);
  return (pos);
}
