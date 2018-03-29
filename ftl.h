/*
** ftl.h for ftl in /Users/vanhem_n/Documents/ftl/ftl.h
**
** Made by VANHEMELRYCK nathan
** Login   <vanhem_n@etna-alternance.net>
**
** Started on  Mon Nov 6- 09:05:00 2017 VANHEMELRYCK nathan
** Last update thu Nov 7- 16:00:00 2017 VANHEMELRYCK nathan
*/

#ifndef __FTL_H__
#define __FTL_H__

#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct 			 s_freight t_freight;
typedef struct 			 s_container t_container;
typedef struct 			 s_navigation_tools t_navigation_tools;
typedef struct 			 s_ftl_drive t_ftl_drive;
typedef struct 			 s_weapon t_weapon;
typedef struct 			 s_ship t_ship;
typedef struct 			 s_repair_command t_repair_command;
//ajout boucle de jeux
typedef struct 			 s_com t_com;
typedef struct 			 s_enemy t_enemy;


struct 					 s_freight
{
	char				 *item;
	t_freight   		 *next;
	t_freight   		 *prev;
};

struct 					 s_container
{
	int					 nb_elem;
	t_freight   		 *first;
	t_freight   		 *last;
};

struct 					 s_navigation_tools
{
	char				 *system_state;
	int   				 sector;
	int 				 detect; // permet de detecter si double detect
	int   				 evade;
};

struct 					 s_ftl_drive
{
	char				 *system_state;
	int   				 energy;
};

struct 					 s_weapon
{
	char				 *system_state;
	int   				 damage;
};


struct 		 			 s_ship
{
	char				 *name;
	int  		  	   	 hull;
	t_weapon			 *weapon;
	t_ftl_drive  		 *drive;
	t_navigation_tools 	 *nav;
	t_container			 *cont;
	t_enemy				 *enemy;
};

struct 		 			 s_repair_command
{
	char				 *key;
	void 				 (*pf)(t_ship*);
};

//ajout boucle de jeux
struct 					 s_enemy
{
	int				 	 hull;
	int   				 damage;
	int   				 evade;
};

struct 		 			 s_com
{
	char				 *key;
	void 				 (*pf)(t_ship*);
};

void  					 my_putchar(char);
void  				 	 my_putstr(char*);
t_ship 				 	 *create_ship();
int 					 add_weapon_to_ship(t_ship*);
int 					 add_ftl_drive_to_ship(t_ship*);
int 					 add_navigation_tools_to_ship(t_ship*);
int 					 add_container_to_ship(t_ship*);
void 					 add_freight_to_container(t_ship*, t_freight*);
void 					 del_freight_from_container(t_ship*, t_freight*);
void 				     get_bonus(t_ship*);
int						 my_strcmp(const char*, const char*);
char					 *my_strdup(const char *);
void 					 ftl_drive_system_check(t_ship *);
void 					 navigation_tools_system_check(t_ship *);
void					 weapon_system_check(t_ship *);
void 					 system_control(t_ship *);
void 					 ftl_drive_system_repair(t_ship *);
void 					 navigation_tools_system_repair(t_ship *);
void 					 weapon_system_repair(t_ship *);
char					 *readline(void);
void 					 system_repair(t_ship *);
//ajout boucle de jeux
t_ship*  				 makeship(void);
int 					 cli(t_ship *);
t_enemy 				 *createEnemy(void);
void   					 my_put_nbr(int);
void 					 addEnemyToShip(t_ship*, t_enemy *);
void					 enemyAttack(t_ship *);
void 					 systemDown(t_ship*);
void					 shipAttack(t_ship *);
void 					 jump(t_ship *);
void					 jumpEvent(t_ship *);
void 					 statShip(t_ship *);
void 					 detectCargo(t_ship *);
t_freight				 *createFret();
void 					 help(t_ship* );

#endif