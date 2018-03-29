/*
** main.c for ftl in /Users/vanhem_n/Documents/ftl/main.c
**
** Made by VANHEMELRYCK nathan
** Login   <vanhem_n@etna-alternance.net>
**
** Started on  Mon Nov 6- 09:05:00 2017 VANHEMELRYCK nathan
** Last update thu Nov 7- 16:00:00 2017 VANHEMELRYCK nathan
*/

#include "ftl.h"

static const t_com tabopt [] = {
	{"attack", &shipAttack},
	{"detect", &detectCargo},
	{"jump", &jump},
	{"getbonus", &get_bonus},
	{"repair_system", &system_repair},
	{"control_system", &system_control},
	{"stat", &statShip},
	{"help", &help},
	{NULL, NULL},
};

void	victoryOrDie(t_ship *ship) {
	if (ship->hull <= 0) {
		my_putstr("\n\033[31m[Critical] - brèche détecter !\033[00m\n");
		my_putstr("Capitaine... Nous somme perdu....\n");
		my_putstr("\n~~ SO BAD TRY AGAIN ~~\n");
	} else if (ship->drive->energy <= 0) {
		my_putstr("\n\033[31m[Critical] - Reacteur non alimenté\033[00m\n");
		my_putstr("Capitaine, vous avez laissé le reacteur s'eteindre\n");
		my_putstr("Nous ne rentrerons jamais vivant...\n");
		my_putstr("\n~~ NOOB TRY AGAIN ~~\n");
	} else if (ship->nav->sector == 10) {
		my_putstr("\n\033[32mCapitaine, nous avons réussit...\033[00m\n");
		my_putstr("A nous les femmes et le vin\n");
		my_putstr("\n~~ GG WP ~~\n");
	} else {
		my_putstr("\nCapitaine, noooooon ne partez pas....\n");
		my_putstr("\n~~ SEE U SOON ~~\n");
	}
}

int 		cli(t_ship *ship){
	char 	*line;
	int 	i;
	int 	find;

	line = "";
	while (my_strcmp(my_strdup("exit"), line) && ship->hull >= 0 
		&& ship->drive->energy >= 0 && ship->nav->sector != 10) {
		if (ship->enemy)
			enemyAttack(ship);
		my_putstr("\n~> ");
		if (!(line = readline()))
			my_putstr("\033[31m[SYSTEM FAILURE] : le lecteur de commande est bloque\033[00m\n");
		find = i = 0;
		while (i != 8) {
			if (!my_strcmp(tabopt[i].key, line)) {
				tabopt[i].pf(ship);
				find = 1;
			}
			i++;
		}
		if (find == 0 && my_strcmp(my_strdup("exit"), line))
			my_putstr("\033[31m[SYSTEM FAILURE] : commande inconnue\033[00m\n");
	}
	victoryOrDie(ship);
	return (0);
}

void 				help(t_ship* ship) {
	my_putstr("\nCapitaine voici la liste des commande du ");
	my_putstr(ship->name);
	my_putstr("\n► attack : utiliser les puissant cannon de notre beaux vaiseaux");
	my_putstr("\n► detect : lance une detection permetant de récuperer des contener");
	my_putstr("\n► jump : active le moteur de warp afin de changer de systeme");
	my_putstr("\n► getbonus : ouvre les contener récuperer a l'aide de detect");
	my_putstr("\n► repair_system : rentre dans le menu de réparation des systems");
	my_putstr("\n► control_system : permet de vérifié l'intégriter des systems");
	my_putstr("\n► stat : permet de vérifié les statistique de notre vaiseaux\n\n");

}

int 		main(void){
	t_ship 	*ship; 

	srandom(time(NULL));
	my_putstr("Bienvenue Sur My_ftl\n\n");
	ship = makeship();
	my_putstr("\nHey Capitaine, bienvenue a bord de votre vaiseaux le ");
	my_putstr(ship->name);
	my_putstr("\nSi vous avez besoin d'aide je suis la (help)");
	cli(ship);
	return (0);
}