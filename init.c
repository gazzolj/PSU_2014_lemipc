/*
** init.c for lemipc in /home/gazzol_j/rendu/PSU_2014_lemipc
** 
** Made by julien gazzola
** Login   <gazzol_j@epitech.net>
** 
** Started on  Mon Mar  2 14:47:33 2015 julien gazzola
** Last update Wed Mar  4 14:15:28 2015 Jordan Verove
*/

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

  if ((map = init_map()) == NULL)
    return (-1);
  print_map(map);
  return (0);
}
