/*
** container.c for ftl in /Users/vanhem_n/Documents/ftl/container.c
**
** Made by VANHEMELRYCK nathan
** Login   <vanhem_n@etna-alternance.net>
**
** Started on  Mon Nov 6- 09:05:00 2017 VANHEMELRYCK nathan
** Last update thu Nov 7- 16:00:00 2017 VANHEMELRYCK nathan
*/

#include "ftl.h"

int 				add_container_to_ship(t_ship *ship) {
	t_container 	*con;

	my_putstr("ajout du container en cours...\n");
	if ((con = malloc(sizeof(t_container))) == NULL) {
		my_putstr("votre vaisseau a explose lorsque vous avez pose le containe\n");
		return (0);
	}
	con->first = NULL;
	con->last = NULL;
	con->nb_elem = 0;
	ship->cont = con;
	my_putstr("\033[32mle container a ete ajoute avec succes!\033[00m\n");
	return (1);
}

/*
* ici on se sert pas de prev on est en last in first out doublement chainé
*/
void 	add_freight_to_container(t_ship *ship, t_freight *freight) {
	if (ship->cont != NULL) {
		if (ship->cont->first != NULL){
			ship->cont->first->prev = freight;
			freight->next = ship->cont->first;
		} else {
			freight->next = NULL;
		}
		freight->prev = NULL;
		ship->cont->first = freight;
		ship->cont->nb_elem += 1;
	}
}

t_freight			*createFret() {
	int 			r;
	t_freight* 		u;

	u = malloc(sizeof(t_freight));
	u->next = u->prev = NULL;
	r = random() % 101;
	if(r < 70)
		u->item = my_strdup("scrap");
	else {
		r = random() % 101;
		if (r < 33)
			u->item = my_strdup("attackbonus");
		else if (r >= 33 && r < 66)
			u->item = my_strdup("evadebonus");
		else if (r >= 66 && r < 99)
			u->item = my_strdup("energy");
		else
			u->item = my_strdup("scrap");
	}
	return (u);	
}

void 			del_freight_from_container(t_ship *ship, t_freight *freight) {
	t_freight 	*node;

	node = ship->cont->first;
	while (node != NULL){
		if (node == freight){
			if (node->next == NULL && node->prev != NULL)
				node->prev->next = NULL;
			else if (node->prev == NULL && node->next != NULL){
				node->next->prev = NULL;
				ship->cont->first = node->next;
			} else if (node->next == NULL && node->prev == NULL)
			ship->cont->first = NULL;
			else {
				if (node->next != NULL)
					node->next->prev = node->prev;
				if (node->prev != NULL)
					node->prev->next = node->next;
			}
			ship->cont->nb_elem -= 1;
			free(node);
			return;
		}
		node = node->next;
	}
}

void 				get_bonus(t_ship* ship) {
	if (ship->cont->nb_elem != 0) {
		my_putstr("\n ouverture des container..\n");
		while (ship->cont->first != NULL) {
			if(!my_strcmp(ship->cont->first->item, my_strdup("attackbonus"))) {
				my_putstr("attack +5\n");
				ship->weapon->damage += 5;
			}
			else if (!my_strcmp(ship->cont->first->item, my_strdup("evadebonus"))) {
				my_putstr("evade +5\n");
				ship->nav->evade += 3;
			}
			else if (!my_strcmp(ship->cont->first->item, my_strdup("energy"))) {
				my_putstr("energy +1\n");
				ship->drive->energy += 1;
			} else {
				my_putstr("hull +1\n");
				ship->hull += 1;
			}
			del_freight_from_container(ship, ship->cont->first);
		}
	} else
	my_putstr("\n Vous n'avez rien dans votre soute...\n");
}
