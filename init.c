/*
** init.c for lemipc in /home/gazzol_j/rendu/PSU_2014_lemipc
** 
** Made by julien gazzola
** Login   <gazzol_j@epitech.net>
** 
** Started on  Mon Mar  2 14:47:33 2015 julien gazzola
** Last update Wed Mar  4 16:05:19 2015 julien gazzola
*/

#include <unistd.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <stdio.h>

void	print_map(char *map)
{
  printf("%s\n", map);
}

char	*init_map()
{
  char	*map;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((map = malloc((11 * 10 * sizeof(char)) + 1)) == NULL)
    return (NULL);
  while (i != 110)
    {
      if (j == 10)
	{
	  map[i] = '\n';
	  j = 0;
	}
      else
	{
	  map[i] = '.';
	  j = j + 1;
	}
      i = i + 1;
    }
  map[i] = '\0';
  return (map);
}

int	main()
{
  key_t	key;
  char	*map;
  char	*my_pwd;
  int	shmid;
  void	*mem;

  if ((map = init_map()) == NULL)
    return (-1);
  if ((my_pwd = getcwd(0, 0)) == NULL)
    return (-1);
  if ((key = (ftok(my_pwd, 0))) == -1)
    return (-1);
  printf("%d\n", key);
  if ((shmid = shmget(key, 110, SHM_R | SHM_W)) == -1)
    shmid = shmget(key, 110, IPC_CREAT | SHM_R | SHM_W);
  if ((mem = shmat(shmid, NULL, SHM_R | SHM_W)) == (void*)-1)
    return (-1);
  
  sprintf((char *)mem, "salut");
  printf("voici la map\n%s\n", (char*)mem);
//  print_map(map);
  shmctl(shmid, IPC_RMID, NULL);
  return (0);
}
