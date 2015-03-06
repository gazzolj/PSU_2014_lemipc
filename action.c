/*
** action.c for lemipc in /home/verove_j/rendu/PSU_2014_lemipc
** 
** Made by Jordan Verove
** Login   <verove_j@epitech.net>
** 
** Started on  Thu Mar  5 16:36:46 2015 Jordan Verove
** Last update Fri Mar  6 12:53:16 2015 Jordan Verove
*/

#include <unistd.h>
#include <stdio.h>

int		do_action(char *map, char team, int pos)
{
  print_map(map);
  printf("\n\n");
  pos = move_left(map, team + 48, pos);
  print_map(map);
  sleep(1);
  pos = move_up(map, team + 48, pos);
  print_map(map);
  printf("\n\n");
  sleep(1);
  pos = move_right(map, team + 48, pos);
  print_map(map);
  printf("\n\n");
  sleep(1);
  pos = move_down(map, team + 48, pos); 
  print_map(map);
  printf("\n\n");
  return (0);
}
