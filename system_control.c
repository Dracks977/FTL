/*
** system_control.c for ftl in /Users/vanhem_n/Documents/ftl/system_control.c
**
** Made by VANHEMELRYCK nathan
** Login   <vanhem_n@etna-alternance.net>
**
** Started on  Mon Nov 6- 09:05:00 2017 VANHEMELRYCK nathan
** Last update thu Nov 7- 16:00:00 2017 VANHEMELRYCK nathan
*/

#include "ftl.h"

void 		ftl_drive_system_check(t_ship *ship) {
	my_putstr("\nverification du reacteur en cours...\n");
	(my_strcmp(ship->drive->system_state, my_strdup("online"))) ? 
	my_putstr("\033[31mreacteur hors service!\033[00m\n\n") : my_putstr("\033[32mreacteur OK!\033[00m\n\n");
}

void 		navigation_tools_system_check(t_ship *ship) {
	my_putstr("\nverification du systeme de navigation en cours...\n");
	(my_strcmp(ship->nav->system_state, my_strdup("online"))) ? 
	my_putstr("\033[31msysteme de navigation hors service!\033[00m\n\n") : my_putstr("\033[32msysteme de navigation OK!\033[00m\n\n");
}

void 		weapon_system_check(t_ship *ship) {
	my_putstr("\nverification du systeme d'armement en cours..\n");
	(my_strcmp(ship->weapon->system_state, my_strdup("online"))) ? 
	my_putstr("\033[31msysteme d'armement hors service!\033[00m\n\n") : my_putstr("\033[32msysteme d'armement OK!\033[00m\n\n");
}

void 		system_control(t_ship *ship) {
	ftl_drive_system_check(ship);
	navigation_tools_system_check(ship);
	weapon_system_check(ship);
}

char		*readline(void)
{
  ssize_t	ret;
  char		*buff;

  if ((buff = malloc((50 + 1) * sizeof(char))) == NULL)
    return (NULL);
  if ((ret = read(0, buff, 50)) > 1)
    {
      buff[ret - 1] = '\0';
      return (buff);
    }
  free(buff);
  return (NULL);
}