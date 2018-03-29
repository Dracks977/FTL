/*
** ship_act.c for ftl in /Users/vanhem_n/Documents/ftl/ship_act.c
**
** Made by VANHEMELRYCK nathan
** Login   <vanhem_n@etna-alternance.net>
**
** Started on  Mon Nov 6- 09:05:00 2017 VANHEMELRYCK nathan
** Last update thu Nov 7- 16:00:00 2017 VANHEMELRYCK nathan
*/

#include "ftl.h"

/* conteneur + esquive ship enemy*/

void		shipAttack(t_ship *ship) {
	int		r;
	if(!my_strcmp(ship->weapon->system_state, my_strdup("online"))) {
		r = random() % 101;
		if (ship->enemy){
			if (r > ship->enemy->evade) {
				my_putstr("\n\033[32mNous avons touché l'enemy\033[00m\n");
				if((ship->enemy->hull -= ship->weapon->damage) <= 0) {
					my_putstr("\033[32mCapitaine, nous avons neutralisé l'enemy\033[00m\n");
					free(ship->enemy);
					ship->enemy = NULL;
					r = random() % 101;
					if(r < 50) {
						ship->drive->energy--;
						my_putstr("Capitaine, ce combat nous a couté 1 point d'énergie\n");
					}
				}
			} else
			my_putstr("\n\033[31mNous avons loupé l'enemy\033[00m\n");
		} else 
		my_putstr("\nCapitaine, il n'y a personne à attaqué...\n");
	} else
	my_putstr("\n\033[31m[Warning] - Armement HS\033[00m\n");
}

void 		jump(t_ship *ship)	{
	if (!my_strcmp(ship->drive->system_state, my_strdup("online")) 
		&& ship->enemy == NULL) {
		if(ship->drive->energy > 0) {
			ship->drive->energy--;
			jumpEvent(ship);
		} else
		my_putstr("Capitaine, nous n'avons plus d'energy, nous somme perdu....\n");
	} else {
		my_putstr("Capitaine, nous ne pouvons pas jumper, ");
		my_putstr("verifié les reacteurs et assurer vous que nous somme hors de danger\n");
	}

}

void 	statShip(t_ship *ship) {
	my_putstr("\n--------Stat--------\n");
	my_putstr("► Hull : ");
	my_put_nbr(ship->hull);
	my_putstr("\n► Damage : ");
	my_put_nbr(ship->weapon->damage);
	my_putstr("\n► Energy : ");
	my_put_nbr(ship->drive->energy);
	my_putstr("\n► evade : ");
	my_put_nbr(ship->nav->evade);
	my_putstr("\n► cargo : ");
	my_put_nbr(ship->cont->nb_elem);
	my_putstr("\n--------------------\n");

}

void		jumpEvent(t_ship *ship) {
	int		r;

	my_putstr("WarpDrive active.....\n");
	my_putstr("landing on sector : ");
	ship->nav->sector++;
	ship->nav->detect = 0; 
	my_put_nbr(ship->nav->sector);
	my_putstr(" \n\n");
	r = random() % 101;
	if(r <= 30 && ship->nav->sector != 10) {
		addEnemyToShip(ship, createEnemy());
	}
}

void 		detectCargo(t_ship *ship) {
	int 	r;
	int 	i;
	if (!my_strcmp(ship->nav->system_state, my_strdup("online"))) {
		if (ship->nav->detect == 0) {
			my_putstr("\nDétection en cours......\n");
			ship->nav->detect = 1;
			r = random() % 101;
			i = 0;
			if(r < 90) {
				my_putstr("Capitaine nous avons trouvé 10 contener !\n");
				while (i != 10) {
					add_freight_to_container(ship, createFret());
					i++;
				}
			} else
			my_putstr("Capitaine nous n'avons rien trouvé...\n");
		} else
		my_putstr("\nCapitaine, il n'y a rien a detecter....\n");
	} else
	my_putstr("\n\033[31m[Warning] - navigation HS\033[00m\n");
}