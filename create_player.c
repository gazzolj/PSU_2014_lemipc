/*
** create_player.c for lemipc in /home/verove_j/rendu/PSU_2014_lemipc
** 
** Made by Jordan Verove
** Login   <verove_j@epitech.net>
** 
** Started on  Thu Mar  5 10:55:45 2015 Jordan Verove
** Last update Fri Mar  6 11:37:06 2015 Jordan Verove
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int		check_team_alive(char *map, char team)
{
  int		i;

  i = 0;
  while (map[i] != '\0')
    {
      //      printf("map[i] : %c  ----- team : %c \n", map[i], team + 48);
      if (map[i] == (team + 48))
	{
	  printf("bite\n");
	  return (1);
	}
      i = i + 1;
    }
  return (-1);
}

int		create_player(char *map, char *number)
{
  int		pos;

  printf("player\n");
  if (strlen(number) != 1)
    return (-1);
  pos = rand() % 900;
  while (map[pos] != '.')
    pos = rand() % 900;
  map[pos] = number[0];
  return (pos);
}

int		create_random_player(char *map, char **arg1)
{
  char		rand_value;
  int		pos;

  printf("random_player\n");
  if ((*arg1 = malloc(1 *sizeof(char))) == NULL)
    return (-1);
  rand_value = rand() % 10;
  *arg1[0] = rand_value;
  pos = rand() % 900;
  while (map[pos] != '.')
    pos = rand() % 900;
  map[pos] = rand_value + 48;
  printf("random_player\n");
  return (pos);
}

int		check_number_player(char *map, char *arg1)
{
  int		number;
  int		pos;

  print_map(map);
  if (arg1 != NULL)
    if ((number = atoi(arg1)) < 0 || (number = atoi(arg1)) > 9)
      return (-1);
  if (arg1 == NULL)
    {
      if ((pos = create_random_player(map, &arg1)) == -1)
	return (-1);
    }
  else
    if ((pos = create_player(map, arg1)) == -1)
      return (-1);
  printf("arg[0] : %c\n", arg1[0] + 48);
  while (check_team_alive(map, arg1[0]) == 1)
    {
      printf("caca\n");
      //      print_map(map);
      do_action(map, arg1[0], pos);
    }
}
