/*
** lemipc.h for lemipc in /home/verove_j/rendu/PSU_2014_lemipc
** 
** Made by Jordan Verove
** Login   <verove_j@epitech.net>
** 
** Started on  Sat Mar  7 12:15:07 2015 Jordan Verove
** Last update Sat Mar  7 12:25:14 2015 Jordan Verove
*/

#ifndef LEMIPC_H_
# define LEMIPC_H_

# include <sys/types.h>
# include <sys/ipc.h>

/*
** init.c
*/

void	print_map(char *map);
char	*create_map(char *map);
char	*init_map(int shmid, char *map, key_t key);
int	init_shared_memory(char *arg1, key_t key);

/*
** create_player.c
*/

int	check_team_alive(char *map, char team);
int	create_player(char *map, char *number);
int	create_random_player(char *map, char **arg1);
int	check_number_player(char *map, char *arg1);

/*
** action.c
*/

int	do_action(char *map, char team, int pos);
char	*check_arround1(char *map, int pos);
char	*check_arround2(char *arround, int pos, char *map);
int	check_if_dead(char *arround);
int	check_if_last(char *map);

/*
** move.c
*/

int	move_left(char *map, char team, int pos);
int	move_right(char *map, char team, int pos);
int	move_up(char *map, char team, int pos);
int	move_down(char *map, char team, int pos);

#endif /* !LEMIPC_H_ */
