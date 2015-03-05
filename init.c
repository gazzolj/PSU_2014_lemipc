/*
** init.c for lemipc in /home/gazzol_j/rendu/PSU_2014_lemipc
** 
** Made by julien gazzola
** Login   <gazzol_j@epitech.net>
** 
** Started on  Mon Mar  2 14:47:33 2015 julien gazzola
** Last update Thu Mar  5 14:37:15 2015 Jordan Verove
*/

#include <unistd.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <stdio.h>

void	print_map(char *map)
{
  int	i;

  i = 0;
  while (map[i] != '\0')
    {
      if (i != 0 && i % 10 == 0)
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
  while (i != 100)
    {
      map[i] = '.';
      i = i + 1;
    }
  map[i] = '\0';
  return (map);
}

int	init_map(int shmid, char *map, key_t key)
{
  shmid = shmget(key, 100, IPC_CREAT | SHM_R | SHM_W);
  if ((map = shmat(shmid, NULL, SHM_R | SHM_W)) == (void*)-1)
    return (-1);
  if ((map = create_map(map)) == NULL)
    return (-1);
  print_map(map);
  //printf("voici la map\n%s\n", (char*)map);
}

int	init()
{
  key_t	key;
  char	*my_pwd;
  int	shmid;
  char	*map;

  if ((my_pwd = getcwd(0, 0)) == NULL)
    return (-1);
  if ((key = (ftok(my_pwd, 0))) == -1)
    return (-1);
  if ((shmid = shmget(key, 100, SHM_R | SHM_W)) == -1)
    {
      if (init_map(shmid, map, key) == -1)
	return (-1);
    }
  else
    {
      if ((map = shmat(shmid, NULL, SHM_R | SHM_W)) == (void*)-1)
        return (-1);
      print_map(map);
      shmctl(shmid, IPC_RMID, NULL);
    }
  return (0);
}

int	main(int ac, char **av)
{
  init();
}
