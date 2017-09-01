#include "Skill.h"

class Role{
public:
	Role(int type);
	~Role();
	
	char* getName();
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
	int setAttack(int attack);
	int getDefend();
	int setDefend(int defend);
	int getExp();
	int setExp(int exp);
	int getLevel();
	int setLevel(int level);
	int getMoney();
	int setMoney(int money);
	
	void showRole();//人物属性 当前装备
	void Bag();

private:
	char name[20];
	int type;
	int health_max;
	int health;
	int magic_max;
	int magic;
	int attack;
	int exp;
	int level;
	int defend;
	int money;
	int bag[20] = {0,};
};