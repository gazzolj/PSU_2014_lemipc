/*
** init.c for lemipc in /home/gazzol_j/rendu/PSU_2014_lemipc
** 
** Made by julien gazzola
** Login   <gazzol_j@epitech.net>
** 
** Started on  Mon Mar  2 14:47:33 2015 julien gazzola
** Last update Sat Mar  7 15:58:02 2015 Jordan Verove
*/

#include <unistd.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <stdio.h>

#include "lemipc.h"

void	print_map(char *map)
{
  int	i;

  i = 0;
  system("clear");
  while (map[i] != '\0')
    {
      if (i != 0 && i % 30 == 0)
	printf("\n");
      printf("%c", map[i]);
      i = i + 1;
    }
  printf("\n");
}

char	*create_map(char *map)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i != 900)
    {
      map[i] = '.';
      i = i + 1;
    }
  map[i] = '\0';
  return (map);
}

char	*init_map(int shmid, char *map, key_t key)
{
  shmid = shmget(key, 900, IPC_CREAT | SHM_R | SHM_W);
  if ((map = shmat(shmid, NULL, SHM_R | SHM_W)) == (void*)-1)
    return (NULL);
  if ((map = create_map(map)) == NULL)
    return (NULL);
  return (map);
}

int	init_shared_memory(char *arg1, key_t key)
{
  char	*map;
  int	shmid;
  
  if ((shmid = shmget(key, 900, SHM_R | SHM_W)) == -1)
    {
      if ((map = init_map(shmid, map, key)) == NULL)
	return (-1);
      if (check_number_player(map, arg1) == -1)
	return (-1);
    }
  else
    {
      if ((map = shmat(shmid, NULL, SHM_R | SHM_W)) == (void*)-1)
        return (-1);
      if (check_number_player(map, arg1) == -1)
	{
	  if (check_if_last(map) == 1)
	    shmctl(shmid, IPC_RMID, NULL);
	  return (-1);
	}
    }
  return (0);
}

int	main(int ac, char **av)
{
  key_t	key;
  char	*my_pwd;
  
  srand(time(NULL));
  if ((my_pwd = getcwd(0, 0)) == NULL)
    return (-1);
  if ((key = (ftok(my_pwd, 0))) == -1)
    return (-1);
  if (ac == 1)
    {
      if (init_shared_memory(NULL, key) == -1)
	return (-1);
    }
  else if (ac == 2)
    if (init_shared_memory(av[1], key) == -1)
      return (-1);
}
