/*
** enemy.c for ftl in /Users/vanhem_n/Documents/ftl/enemy.c
**
** Made by VANHEMELRYCK nathan
** Login   <vanhem_n@etna-alternance.net>
**
** Started on  Mon Nov 6- 09:05:00 2017 VANHEMELRYCK nathan
** Last update thu Nov 7- 16:00:00 2017 VANHEMELRYCK nathan
*/

#include "ftl.h"

void    my_put_nbr(int n)
{
	if (n == -2147483648)
		my_putstr("-2147483648");
	else{
		if (n < 0){
			my_putchar('-');
			n = -n;
		}
		if (n > 9)
			my_put_nbr(n / 10);
		my_putchar((n % 10) + '0');
	}
}

void			enemyAttack(t_ship *ship) {
	int			r;

	r = random() % 101;
	if ((r > ship->nav->evade)){
		ship->hull = ship->hull - ship->enemy->damage;
		my_putstr("\n\033[31mCaptitaine, l'enemie nous à touché\033[00m\n");
		if (ship->hull - ship->enemy->damage < 0)
			my_putstr("\n\033[31m[Critical] - intégriter du vaiseaux menacé\033[00m\n");
		r = random() % 101;
		if (r <= 20)
			systemDown(ship);
	} else
	my_putstr("\n\033[32mCaptitaine, on nous à manqué\033[00m\n");
}

void 	systemDown(t_ship* ship) {
	int			r;

	r = random() % 101;
	if(r < 33) {
		free(ship->drive->system_state);
		my_putstr("\033[31m[WARNING] - Réacteur touché\033[00m\n");
		ship->drive->system_state =  my_strdup("offline");
	} else if (r >= 33 && r < 66) {
		free(ship->nav->system_state);
		my_putstr("\033[31m[WARNING] - Systeme de navigation touché\033[00m\n");
		ship->nav->system_state =  my_strdup("offline");
	} else {
		free(ship->weapon->system_state);
		my_putstr("\033[31m[WARNING] - Systeme d'armement touché\033[00m\n");
		ship->weapon->system_state =  my_strdup("offline");
	}
}

t_enemy 		*createEnemy(void) {
	static int 	eEnenemy = 0;
	static int  att = 0;
	static int  lif = 0;
	t_enemy 	*en;

	if ((en = malloc(sizeof(t_enemy))) == NULL) {
		my_putstr("Oops something go wrong\n");
		return (NULL);
	}
	att = en->hull = 1.5 * att + ((eEnenemy == 0)? 20:0);
	lif = en->damage = 1.5 * lif + ((eEnenemy == 0)? 10:0);
	en->evade = 5 + (random() % 26);
	eEnenemy++;
	return (en);
}

void addEnemyToShip(t_ship* ship, t_enemy *en) {
	if (ship->enemy == NULL) {
		ship->enemy = en;
		my_putstr("Un enemy vous attack, vos capteur dectect qu'il a ");
		my_put_nbr(ship->enemy->hull);
		my_putstr(" de point de coque et une puissance d'attaque de ");
		my_put_nbr(ship->enemy->damage);
		my_putstr("\nsa capacité d'evasion est de ");
		my_put_nbr(ship->enemy->evade);
		my_putstr("\nCapitaine il est temps de les faire rejoindre la vahala !!\n\n");
	}
}