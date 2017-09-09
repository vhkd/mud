#ifndef ENEMY_H
#define ENEMY_H

#include <string>

using namespace std;

class Enemy {

public:
	Enemy();
	~Enemy();
	string getName();
	void setType(int whattype);
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

	int getGoodsId();		//掉落物品
	int getExp();			//增加经验
	int getMoney();			//增加金钱

	double useSkill();	//怪物使用技能，返回伤害数值

	void showEnemy();

protected:
	string name;
	int type;
	int health_max;
	int health;
	int magic_max;
	int magic;
	int attack;
	int defend;

	int goodsId; //打死怪物会掉落的物品
	int exp;  //打死怪物增加的经验
	int money;  //打死怪物增加的金钱
};

class Enemy_Small :public Enemy {	//小怪
public:
	Enemy_Small();
	~Enemy_Small();
};

class Enemy_Boss :public Enemy { //大怪
public:
	Enemy_Boss();
	Enemy_Boss(int type);
	~Enemy_Boss();

};

//怪物一

class Enemy_1 :public Enemy_Boss {
public:
	Enemy_1();
	~Enemy_1();
	double useSkill();
};

//怪物二

class Enemy_2 :public Enemy_Boss {
public:
	Enemy_2();
	~Enemy_2();
	double useSkill();
};

//怪物三

class Enemy_3 :public Enemy_Boss {
public:
	Enemy_3();
	~Enemy_3();
	double useSkill();
};

//怪物四

class Enemy_4 :public Enemy_Boss {
public:
	Enemy_4();
	~Enemy_4();
	double useSkill();
};

//怪物五

class Enemy_5 :public Enemy_Boss {
public:
	Enemy_5();
	~Enemy_5();
	double useSkill();
};

//怪物六

class Enemy_6 :public Enemy_Boss {
public:
	Enemy_6();
	~Enemy_6();
	double useSkill();
};

//怪物七

class Enemy_7 :public Enemy_Boss {
public:
	Enemy_7();
	~Enemy_7();
	double useSkill();
};

//怪物八

class Enemy_8 :public Enemy_Boss {
public:
	Enemy_8();
	~Enemy_8();
	double useSkill();
};

#endif