#include "Skill.h"

class Role{
public:
	Role(int type);
	~Role();
	
	string getName();
	int getType();
	int getHealth_max();
	int getHealth();
	int getMagic_max();
	int getMagic();
	int getAttack();
	int getExp();
	int getLevel();
	int getDefend();
	
	void showRole();//人物属性 当前装备
	void Bag();

private:
	string name;
	int type;
	int health_max;
	int health;
	int magic_max;
	int magic;
	int attack;
	int exp;
	int level;
	int defend;
	int bag[20] = {0,};
}