##
## Makefile for ftl in /Users/vanhem_n/Documents/ftl/Makefile
##
## Made by VANHEMELRYCK nathan
## Login   <vanhem_n@etna-alternance.net>
##
## Started on  Mon Nov 6- 09:01:00 2017 VANHEMELRYCK nathan
## Last update thu Nov 6- 15:00:00 2017 VANHEMELRYCK nathan
##

CC 	 	= 	gcc
NAME 	= 	ftl
#pensez a clean tmain
SRC 	=	main.c				\
			enemy.c 			\
			ship_act.c 			\
			echo.c				\
			air_shed.c			\
			container.c			\
			system_control.c 	\
			system_repair.c

OBJ		= $(SRC:%.c=%.o)
CFLAGS 	= -W -Wall -Wextra -Werror
RM 		= rm -f

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all:		$(NAME)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:	fclean all