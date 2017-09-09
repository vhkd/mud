#ifndef ROLE_H
#define ROLE_H

#include <string>
#include "Skill.h"
#include "Bag.h"

using namespace std;

class Role {
public:
	Role(int type);
	~Role();

	string getName();
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

	int getExp();
	int setExp(int e);
	int getExp_max();

	int getLevel();
	int setLevel(int l);

	int getMoney();
	int setMoney(int m);

	void getBag();
	bool setBag(int goodsId);  //返回是否成功加入背包（背包是否已满）

	void showRole();//人物属性 当前装备
	bool showSkill();//显示技能,返回是否可以使用技能

	double useSkill();		//使用技能,返回技能的攻击力加成

private:
	string name;
	int type;
	int health_max;
	int health;
	int magic_max;
	int magic;
	int attack;
	int exp;
	int exp_Max;		//线性经验值，暂定为最高300
	int level;
	int defend;			//防御
	int money;
	int bag[20];
	Skill skill;		//他所拥有的技能
	int skillLevel;		//升级带来的技能升级点数
};
#endif