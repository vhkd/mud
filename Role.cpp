#include <iostream>
#include "Role.h"

using namespace std;

Role::Role(int t)//1战士2剑客3法师
{
	switch (t)
	{
	case '1': {
		name[20] = '11111';
		type = 1;
		health_max = 160;
		health = 160;
		magic_max = 100;
		magic =100;
		attack = 30;
		exp = 0;
		level = 1;
		defend = 10;
		money = 0;
		break;
	}
	case '2': {
		name[20] = '22222';
		type = 2;
		health_max = 200;
		health = 200;
		magic_max = 100;
		magic = 100;
		attack = 30;
		exp = 0;
		level = 1;
		defend = 20;
		money = 0;
		break;
	}
	case '3': {
		name[20] = '33333';
		type = 3;
		health_max = 120;
		health = 120;
		magic_max = 100;
		magic = 100;
		attack = 45;
		exp = 0;
		level = 1;
		defend = 10;
		money = 0;
		break;
	}
	default:
		break;
	}
}

Role::~Role()
{
}

char * Role::getName()
{
	return *name;
}

int Role::getType()
{
	return type;
}

int Role::getHealth_max()
{
	return health_max;
}

int Role::setHealth_max(int hp_m)
{
	health_max = hp_m;
	return 0;
}

int Role::getHealth()
{
	return health;
}

int Role::setHealth(int hp)
{
	health = hp;
	return 0;
}

int Role::getMagic_max()
{
	return magic_max;
}

int Role::setMagic_max(int mp_m)
{
	magic_max = mp_m;
	return 0;
}

int Role::getMagic()
{
	return magic;
}

int Role::setMagic(int mp)
{
	magic = mp;
	return 0;
}

int Role::getAttack()
{
	return attack;
}

int Role::setAttack(int a)
{
	attack = a;
	return 0;
}

int Role::getDefend()
{
	return defend;
}

int Role::setDefend(int d)
{
	defend = d;
	return 0;
}

int Role::getExp()
{
	return exp;
}

int Role::setExp(int e)
{
	exp = e;
	return 0;
}

int Role::getLevel()
{
	return level;
}

int Role::setLevel(int l)
{
	level = l;
	return 0;
}

int Role::getMoney()
{
	return money;
}

int Role::setMoney(int m)
{
	money = m;
	return 0;
}

void Role::showRole()
{
	cout << "当前人物属性:" << endl;
	cout << "姓名:" << name << endl;
	cout << "等级:" << level << endl;
	cout << "生命值:" << health << "/" << health_max << endl;
	cout << "魔法值:" << magic << "/" << magic_max << endl;
	cout << "攻击:" << attack << endl;
	cout << "防御:" << defend << endl;
	cout << "金钱:" << money << endl;
}

void Role::Bag()
{
}
