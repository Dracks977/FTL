/*
** air_shed.c for ftl in /Users/vanhem_n/Documents/ftl/air_shed.c
**
** Made by VANHEMELRYCK nathan
** Login   <vanhem_n@etna-alternance.net>
**
** Started on  Mon Nov 6- 09:05:00 2017 VANHEMELRYCK nathan
** Last update thu Nov 7- 16:00:00 2017 VANHEMELRYCK nathan
*/

#include "ftl.h"

t_ship* 		create_ship() {
	t_ship		*ship;

	my_putstr("construction du vaisseau en cours...\n");
	if ((ship = malloc(sizeof(t_ship))) == NULL) {
		my_putstr("\033[31mle vaisseau n'a pas pu etre construit par manque de materiaux\n\033[00m");
		return (NULL);
	}
	ship->hull = 50;
	ship->name = "Nebuchadnezzar";
	ship->weapon = NULL;
	ship->drive = NULL;
	ship->nav = NULL;
	ship->cont = NULL;
	ship->enemy = NULL;
	my_putstr("\033[32mamelioration du vaisseau termine!\n\033[00m");
	return (ship);
}

int 			add_weapon_to_ship(t_ship *ship) {
	t_weapon 	*wep;

	my_putstr("ajout des armes en cours...\n");
	if ((wep = malloc(sizeof(t_weapon))) == NULL) {
		my_putstr("\033[31mvotre vaisseau a explose quand vous avez tente d'ajouter les armes\n\033[00m");
		return (0);
	}
	wep->system_state =  my_strdup("online");
	wep->damage = 10;
	ship->weapon = wep;
	my_putstr("\033[32mles armes on ete ajoutes avec succes!\033[00m\n");
	return (1);
}

int 			add_ftl_drive_to_ship(t_ship *ship) {
	t_ftl_drive 	*drive;

	my_putstr("ajout du reacteur en cours...\n");
	if ((drive = malloc(sizeof(t_ftl_drive))) == NULL) {
		my_putstr("\033[31mvotre vaisseau a explose lorsque vous avez pose le reacteur\n\033[00m");
		return (0);
	}
	drive->system_state = my_strdup("online");
	drive->energy = 11;
	ship->drive = drive;
	my_putstr("\033[32mle reacteur a ete ajoute avec succes!\n\033[00m");
	return (1);
}

int 			add_navigation_tools_to_ship(t_ship *ship) {
	t_navigation_tools 	*nav;

	my_putstr("ajout des outils de navigations...\n");
	if ((nav = malloc(sizeof(t_navigation_tools))) == NULL) {
		my_putstr("\033[31mvotre vaisseau a explose lorsque vous avez pose les outils de navigations\n\033[00m");
		return (0);
	}
	nav->system_state =  my_strdup("online");
	nav->sector = -1; //le jeux commence au 1er jump
	nav->evade = 25;
	nav->detect = 1;
	ship->nav = nav;
	my_putstr("\033[32mles outils de navigations ont ete ajoutes avec succes!\n\033[00m");
	return (1);
}

t_ship*  	makeship(void) {
	t_ship *ship = create_ship();
	add_weapon_to_ship(ship);
	add_ftl_drive_to_ship(ship);
	add_navigation_tools_to_ship(ship);
	add_container_to_ship(ship);
	return (ship);
}