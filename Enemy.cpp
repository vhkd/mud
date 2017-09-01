#include "Enemy.h"

Enemy::Enemy(int t)
{
	switch (t)
	{
	case'1': {

		break;
	}
	case'2': {

		break;
	}
	case'3': {

		break;
	}
	
	default:
		break;
	}
}

Enemy::~Enemy()
{
}
char * Enemy::getName()
{
	return *name;
}

int Enemy::getType()
{
	return type;
}

int Enemy::getHealth_max()
{
	return health;
}

int Enemy::setHealth_max(int hp_m)
{
	health_max = hp_m;
	return 0;
}

int Enemy::getHealth()
{
	return health;
}

int Enemy::setHealth(int hp)
{
	health = hp;
	return 0;
}

int Enemy::getMagic_max()
{
	return magic_max;
}

int Enemy::setMagic_max(int mp_m)
{
	magic_max = mp_m;
	return 0;
}

int Enemy::getMagic()
{
	return magic;
}

int Enemy::setMagic(int mp)
{
	magic = mp;
	return 0;
}

int Enemy::getAttack()
{
	return attack;
}

int Enemy::setAttack(int a)
{
	attack = a;
	return 0;
}

int Enemy::getDefend()
{
	return defend;
}

int Enemy::setDefend(int d)
{
	defend = d;
	return 0;
}
