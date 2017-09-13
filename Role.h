﻿#ifndef ROLE_H
#define ROLE_H

#include <string>
#include "Skill.h"
#include "Bag.h"

using namespace std;

class Role {
public:
	Role(int type);
	Role(string name, int type, int health_max, int health, int magic_max, int magic, int attack, int exp, int level, int defend, int money, int mapId, int story, int weapon, int clothes);
	~Role();

	void operator =(Role player);

	string getName();
	int getType();

	int getHealth_max();
	void setHealth_max(int hp_m);

	int getHealth();
	void setHealth(int hp);

	int getMagic_max();
	void setMagic_max(int mp_m);

	int getMagic();
	void setMagic(int mp);

	int getAttack();
	void setAttack(int a);

	int getDefend();
	void setDefend(int d);

	int getExp();
	void setExp(int e);
	int getLevelExp_max(int whichLevel);

	int getLevel();
	void setLevel(int l);

	int getMoney();
	void setMoney(int m);

	int getMapId();
	void setMapId(int NewMapId);

	int getStory();
	void setStory(int s);

	int getWeapon();
	void setWeapon(int w);
	int getClothes();
	void setClothes(int c);

	Skill getSkill();
	Bag getBag();
	void showBag();//显示背包
	void addGoodsToBag(int *goodsId, int* num);//加入背包,重载应对两种情况
	void addGoodsToBag(int goodsId, int num);

	void setBag(Bag bags);  

	void showRole();//人物属性 当前装备
	bool showSkill();//显示技能,返回是否可以使用技能

	double useSkill();		//使用技能,返回技能的攻击力加成

	void showEquip();//展示当前装备
	void wearEquip(int id);//穿上装备
	void removeEquip(int id);//脱下装备

private:
	string name;
	int type;
	int health_max;
	int health;
	int magic_max;
	int magic;
	int attack;
	int exp;
	//每个等级对应的最高经验值，经验值大于等于就升级
	const int levelExp_Max[29] = { 6,12,18,24,30,36,42,48,54,60,69,78,87,96,105,114,123,132,141,150,162,174,186,198,210,225,240,270,300 };
	int exp_Max;		//线性经验值，暂定为最高300
	int level;
	int defend;			//防御
	int money;
	Bag bag;			//背包
	//int bag[20];
	int mapId;			//记录玩家当前所在地
	Skill skill;		//他所拥有的技能
	int skillLevel;		//升级带来的技能升级点数
	int story = 0;//剧情节点

	int weapon = -1;//当前武器id  默认-1为无
	int clothes = -1; //当前防具id

	Goods goods[24] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23 };
};
#endif