#include <iostream>
#include "Enemy.h"

using namespace std;

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

string Enemy::getName() {
	return name;
}

void Enemy::setType(int whatType) {
	type = whatType;
}

int Enemy::getType() {
	return type;
}

int Enemy::getHealth_max() {
	return health;
}

int Enemy::setHealth_max(int hp_m) {
	health_max = hp_m;
	return 0;
}

int Enemy::getHealth() {
	return health;
}

int Enemy::setHealth(int hp) {
	health = hp;
	return 0;
}

int Enemy::getMagic_max() {
	return magic_max;
}

int Enemy::setMagic_max(int mp_m) {
	magic_max = mp_m;
	return 0;
}

int Enemy::getMagic() {
	return magic;
}

int Enemy::setMagic(int mp) {
	magic = mp;
	return 0;
}

int Enemy::getAttack() {
	return attack;
}

int Enemy::setAttack(int a) {
	attack = a;
	return 0;
}

int Enemy::getDefend() {
	return defend;
}

int Enemy::setDefend(int d) {
	defend = d;
	return 0;
}

int Enemy::getGoodsId()
{
	return goodsId;
}

int Enemy::getExp()
{
	return exp;
}

int Enemy::getMoney()
{
	return money;
}

double Enemy::useSkill()
{
	return 0.0;
}

void Enemy::showEnemy() {
	cout << "当前怪物属性:" << endl;
	cout << "名称:" << name << endl;
	cout << "生命值:" << health << "/" << health_max << endl;
	cout << "魔法值:" << magic << "/" << magic_max << endl;
	cout << "攻击:" << attack << endl;
	cout << "防御:" << defend << endl;
}


Enemy_Small::Enemy_Small() {  //小怪统一血量和攻击？
	health = 20;
	attack = 5;
}

Enemy_Boss::Enemy_Boss(int whatType) {
	setType(whatType);
	switch (whatType) {
	case '1': {
		name = "暗影黑狼";
		type = 0;
		health = 150;
		health_max = 150;
		magic = 100;
		magic_max = 100;
		attack = 15;
		defend = 5;

		goodsId = 0;	//打死该怪物会掉落的物品
		exp = 25;		//打死该怪物得到的经验
		money = 30;		//打死该怪物得到的金钱
		break;
	}
	case '2': {
		name = "史诗绯红印记树怪";
		type = 2;
		health = 250;
		health_max = 250;
		magic = 120;
		magic_max = 120;
		attack = 25;
		defend = 10;

		goodsId = 1;	//打死该怪物会掉落的物品
		exp = 35;		//打死该怪物得到的经验
		money = 50;		//打死该怪物得到的金钱
		break;
	}
	case '3': {
		name = "史诗苍老雕文魔像";
		type = 3;
		health = 250;
		health_max = 250;
		magic = 120;
		magic_max = 120;
		attack = 25;
		defend = 10;

		goodsId = 2;	//打死该怪物会掉落的物品
		exp = 35;		//打死该怪物得到的经验
		money = 50;		//打死该怪物得到的金钱
		break;
	}
	case '4': {
		name = "传说级远古石甲虫";
		type = 4;
		health = 200;
		health_max = 200;
		magic = 110;
		magic_max = 110;
		attack = 20;
		defend = 8;

		goodsId = 3;	//打死该怪物会掉落的物品
		exp = 30;		//打死该怪物得到的经验
		money = 40;		//打死该怪物得到的金钱
		break;
	}

	case '5': {
		name = "传说级深红锋啄鸟";
		type = 5;
		health = 200;
		health_max = 200;
		magic = 110;
		magic_max = 110;
		attack = 20;
		defend = 8;

		goodsId = 4;	//打死该怪物会掉落的物品
		exp = 30;		//打死该怪物得到的经验
		money = 40;		//打死该怪物得到的金钱
		break;
	}
	case '6': {
		name = "传说级魔沼蛙";
		type = 6;
		health = 200;
		health_max = 200;
		magic = 110;
		magic_max = 110;
		attack = 20;
		defend = 8;

		goodsId = 6;	//打死该怪物会掉落的物品
		exp = 30;		//打死该怪物得到的经验
		money = 40;		//打死该怪物得到的金钱
		break;
	}
	case '7': {
		name = "炼狱巨龙";
		type = 7;
		health = 500;
		health_max = 500;
		magic = 310;
		magic_max = 310;
		attack = 60;
		defend = 30;

		goodsId = 7;	//打死该怪物会掉落的物品
		exp = 60;		//打死该怪物得到的经验
		money = 110;		//打死该怪物得到的金钱
		break;
	}
	case '8': {
		name = "最强霸龙纳什男爵";
		type = 8;
		health = 800;
		health_max = 800;
		magic = 510;
		magic_max = 510;
		attack = 100;
		defend = 50;

		goodsId = 8;	//打死该怪物会掉落的物品
		exp = 100;		//打死该怪物得到的经验
		money = 500;		//打死该怪物得到的金钱
		break;
	}
	default:break;
	}
}

//怪物一
/*
Enemy_1::Enemy_1(){
name = "暗影黑狼";
type = 0;
health = 150;
health_max = 150;
magic = 100;
magic_max = 100;
attack = 15;
defend = 5;

goodsId = 0;	//打死该怪物会掉落的物品
exp = 25;		//打死该怪物得到的经验
money = 30;		//打死该怪物得到的金钱
}
*/
double Enemy_1::useSkill() {
	if (getMagic() < 20) {
		cout << getName() << "无法发动技能，没有对你造成伤害。" << endl;
		return 0;
	}
	else {
		setMagic(getMagic() - 20);
		cout << getName() << "使用技能，对你造成" << getAttack()*1.2 << "的伤害" << endl;
		return getAttack()*1.2;
	}
}

//怪物二
/*
Enemy_2::Enemy_2(){
name = "史诗绯红印记树怪";
type = 2;
health = 250;
health_max = 250;
magic = 120;
magic_max = 120;
attack = 25;
defend = 10;

goodsId = 1;	//打死该怪物会掉落的物品
exp = 35;		//打死该怪物得到的经验
money = 50;		//打死该怪物得到的金钱
}
*/

double Enemy_2::useSkill() {
	if (getMagic() < 30) {
		cout << getName() << "无法发动技能，没有对你造成伤害。" << endl;
		return 0;
	}
	setMagic(getMagic() - 30);
	cout << getName() << "使用技能，对你造成" << getAttack()*1.4 << "的伤害" << endl;
	return getAttack()*1.4;
}

//怪物三
/*
Enemy_3::Enemy_3(){
name = "史诗苍老雕文魔像";
type = 3;
health = 250;
health_max = 250;
magic = 120;
magic_max = 120;
attack = 25;
defend = 10;

goodsId = 2;	//打死该怪物会掉落的物品
exp = 35;		//打死该怪物得到的经验
money = 50;		//打死该怪物得到的金钱
}
*/

double Enemy_3::useSkill() {
	if (getMagic() < 30) {
		cout << getName() << "无法发动技能，没有对你造成伤害。" << endl;
		return 0;
	}
	setMagic(getMagic() - 30);
	cout << getName() << "使用技能，对你造成" << getAttack()*1.4 << "的伤害" << endl;
	return getAttack()*1.4;
}


//怪物四
/*
Enemy_4::Enemy_4(){
name = "传说级远古石甲虫";
type = 4;
health = 200;
health_max = 200;
magic = 110;
magic_max = 110;
attack = 20;
defend = 8;

goodsId = 3;	//打死该怪物会掉落的物品
exp = 30;		//打死该怪物得到的经验
money = 40;		//打死该怪物得到的金钱
}
*/

double Enemy_4::useSkill() {
	if (getMagic() < 30) {
		cout << getName() << "无法发动技能，没有对你造成伤害。" << endl;
		return 0;
	}
	setMagic(getMagic() - 30);
	cout << getName() << "使用技能，对你造成" << getAttack()*1.4 << "的伤害" << endl;
	return getAttack()*1.4;
}


//怪物五
/*
Enemy_5::Enemy_5(){
name = "传说级深红锋啄鸟";
type = 5;
health = 200;
health_max = 200;
magic = 110;
magic_max = 110;
attack = 20;
defend = 8;

goodsId = 4;	//打死该怪物会掉落的物品
exp = 30;		//打死该怪物得到的经验
money = 40;		//打死该怪物得到的金钱
}

*/
double Enemy_5::useSkill() {
	if (getMagic() < 30) {
		cout << getName() << "无法发动技能，没有对你造成伤害。" << endl;
		return 0;
	}
	setMagic(getMagic() - 30);
	cout << getName() << "使用技能，对你造成" << getAttack()*1.4 << "的伤害" << endl;
	return getAttack()*1.4;
}


//怪物六
/*
Enemy_6::Enemy_6(){
name = "传说级魔沼蛙";
type = 6;
health = 200;
health_max = 200;
magic = 110;
magic_max = 110;
attack = 20;
defend = 8;

goodsId = 6;	//打死该怪物会掉落的物品
exp = 30;		//打死该怪物得到的经验
money = 40;		//打死该怪物得到的金钱
}
*/

double Enemy_6::useSkill() {
	if (getMagic() < 30) {
		cout << getName() << "无法发动技能，没有对你造成伤害。" << endl;
		return 0;
	}
	setMagic(getMagic() - 30);
	cout << getName() << "使用技能，对你造成" << getAttack()*1.4 << "的伤害" << endl;
	return getAttack()*1.4;
}


//怪物七
/*
Enemy_7::Enemy_7(){
name = "巨龙";
type = 7;
health = 500;
health_max = 500;
magic = 310;
magic_max = 310;
attack = 60;
defend = 30;

goodsId = 7;	//打死该怪物会掉落的物品
exp = 60;		//打死该怪物得到的经验
money = 110;		//打死该怪物得到的金钱
}
*/

double Enemy_7::useSkill() {
	if (getMagic() < 80) {
		cout << getName() << "无法发动技能，没有对你造成伤害。" << endl;
		return 0;
	}
	setMagic(getMagic() - 80);
	cout << getName() << "使用技能，对你造成" << getAttack()*1.8 << "的伤害" << endl;
	return getAttack()*1.8;
}


//怪物八
/*
Enemy_8::Enemy_8() {
	name = "最强霸龙纳什男爵";
	type = 8;
	health = 800;
	health_max = 800;
	magic = 510;
	magic_max = 510;
	attack = 100;
	defend = 50;

	goodsId = 8;	//打死该怪物会掉落的物品
	exp = 100;		//打死该怪物得到的经验
	money = 500;		//打死该怪物得到的金钱
}
*/

double Enemy_8::useSkill() {
	if (getMagic() < 120) {
		cout << getName() << "无法发动技能，没有对你造成伤害。" << endl;
		return 0;
	}
	setMagic(getMagic() - 120);
	cout << getName() << "使用技能，对你造成" << getAttack()*2.2 << "的伤害" << endl;
	return getAttack()*2.2;
}