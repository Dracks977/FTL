/*
** system_repair.c for ftl in /Users/vanhem_n/Documents/ftl/system_repair.c
**
** Made by VANHEMELRYCK nathan
** Login   <vanhem_n@etna-alternance.net>
**
** Started on  Mon Nov 6- 09:05:00 2017 VANHEMELRYCK nathan
** Last update thu Nov 7- 16:00:00 2017 VANHEMELRYCK nathan
*/

#include "ftl.h"

static const t_repair_command tabopt [] = {
	{"ftl_drive", &ftl_drive_system_repair},
	{"weapon", &weapon_system_repair},
	{"navigation_tools", &navigation_tools_system_repair}, 
	{NULL, NULL},
};

void 		ftl_drive_system_repair(t_ship *ship) {
	my_putstr("reparation du reacteur en cours...\n");
	free(ship->drive->system_state);
	(ship->drive->system_state =  my_strdup("online")) ? 
	my_putstr("\033[32mreparation termine! systeme reacteur OK!\033[00m\n\n") :
	my_putstr("\033[31mles reparations du reacteur ont echoue\033[00m\n\n");
}

void 		navigation_tools_system_repair(t_ship *ship) {
	my_putstr("reparation du systeme de navigation en cours...\n");
	free(ship->nav->system_state);
	(ship->nav->system_state =  my_strdup("online")) ? 
	my_putstr("\033[32mreparation termine! systeme de navigation OK!\033[00m\n\n") :
	my_putstr("\033[31mles reparations des outils de navigations ont echoue\033[00m\n\n");
}

void 		weapon_system_repair(t_ship *ship) {
	my_putstr("reparation du systeme d'armement en cours...\n");
	free(ship->weapon->system_state);
	(ship->weapon->system_state =  my_strdup("online")) ? 
	my_putstr("\033[32mreparation termine! systeme d'armement OK!\033[00m\n\n") :
	my_putstr("\033[31mles reparations du systeme d'armement ont echoue\033[00m\n\n");	
}

void 		system_repair(t_ship *ship) {
	int 	i;
	char 	*line;
	int 	find;

	my_putstr("\nCapitaine, quelle system voulez vous réparer ? (ftl_drive, weapon, navigation_tools)\n");
	my_putstr("repair_system~>");
	if(!(line = readline()))
		my_putstr("\033[31m[SYSTEM FAILURE] : le lecteur de commande est bloque\033[00m\n");

	find = i = 0;
	while (i != 3) {
		if (!my_strcmp(tabopt[i].key, line)) {
			tabopt[i].pf(ship);
			find = 1;
		}
		i++;
	}
	if (find == 0)
		my_putstr("\033[31m[SYSTEM FAILURE] : commande inconnue\033[00m\n");
}