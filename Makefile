##
## Makefile for lemipc in /home/gazzol_j/rendu/PSU_2014_lemipc
## 
## Made by julien gazzola
## Login   <gazzol_j@epitech.net>
## 
## Started on  Mon Mar  2 14:46:49 2015 julien gazzola
## Last update Mon Mar  2 15:08:58 2015 julien gazzola
##

Cc	=	gcc

RM	=	rm -f

NAME	=	lemipc

SRC	=	init.c

LDFLAGS	=	-Wall -Wextra -Werror -pedantic -I. -ansi

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
