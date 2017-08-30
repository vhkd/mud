#include "Skill.h"

class Enemy {

public:
	FightOrAnswer();
	string getName();
	int getType();
	int getHealth_max();
	int getHealth();
	int getMagic_max();
	int getMagic();
	int getAttack();
	int getDefend();
	
private:
	string name;
	int type;
	int health_max;
	int health;
	int magic_max;
	int magic;
	int attack;
	//int exp;
	//int level;
	int defend;
}
class enemy_small:public Enemy{
	
}

class enemy_boss:public Enemy{
	
}