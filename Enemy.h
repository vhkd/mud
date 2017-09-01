#include "Skill.h"

class Enemy {
public:
	Enemy(int t);
	~Enemy();

	void FightOrAnswer();
	char *getName();
	int getType();
	int getHealth_max();
	int setHealth_max(int hp_m);
	int getHealth();
	int setHealth(int hp);
	
	int getMagic_max();
	int setMagic_max(int mp_m);
	int getMagic();
	int setMagic(int mp);
	int getAttack();
	int setAttack(int a);
	int getDefend();
	int setDefend(int d);
	
private:
	char name[20];
	int type;
	int health_max;
	int health;
	int magic_max;
	int magic;
	int attack;
	int defend;
};

class enemy_small:public Enemy{
	
};

class enemy_boss:public Enemy{
	
};