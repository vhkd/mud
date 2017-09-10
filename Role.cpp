#include <iostream>
#include <string>
#include "Role.h"

using namespace std;

Role::Role(int t){  //1战士2剑客3法师
	switch (t) {
	case 0: {
		type = 0;		//用来判断有没有保存的游戏
		break;
	}
	case 1: {
		name = "11111";
		type = 1;
		health_max = 160;
		health = 160;
		magic_max = 100;
		magic = 100;
		attack = 30;
		exp = 0;
		exp_Max = 300;			//暂定
		level = 1;
		defend = 10;
		money = 0;
		skill = Role_1Skill::Role_1Skill();
		break;
	}
	case 2: {
		name = "22222";
		type = 2;
		health_max = 200;
		health = 200;
		magic_max = 100;
		magic = 100;
		attack = 30;
		exp = 0;
	//	exp_Max = 300;			//暂定
		level = 1;
		defend = 20;
		money = 0;
		skill = Role_2Skill::Role_2Skill();
		break;
	}
	case 3: {
		name = "33333";
		type = 3;
		health_max = 120;
		health = 120;
		magic_max = 100;
		magic = 100;
		attack = 45;
		exp = 0;
		//exp_Max = 300;				//暂定
		level = 1;
		defend = 10;
		money = 0;
		skill = Role_3Skill::Role_3Skill();
		break;
	}
	default:break;
	}
}

void Role::operator=(Role player) {			//重载=实现深复制
	name = player.getName();
	type = player.getType();
	health = player.getHealth_max();
	health = player.getHealth();
	magic_max = player.getMagic_max();
	magic = player.getMagic();
	attack = player.getAttack();
	exp = player.getExp();

	level = player.getLevel();
	defend = player.getDefend();	
	money = player.getMoney();
	bag = player.bag;		

	mapId = player.getMapId();		
	skill = player.skill;		
}

bool Role::showSkill() {    //返回是否有技能释放
	if (skill.getLevel(1) || skill.getLevel(2) || skill.getLevel(3) || skill.getLevel(4) ) {
		cout << "你可以选择使用的技能有：" << endl;
		if (skill.getLevel(1) )
			cout << "1技能：" << skill.getName(1) << ends << skill.getLevel(1) << "点" << '\t';
		if (skill.getLevel(2) )
			cout << "2技能：" << skill.getName(2) << ends << skill.getLevel(2) << "点" << '\t';
		if (skill.getLevel(3) )
			cout << "3技能：" << skill.getName(3) << ends << skill.getLevel(3) << "点" << '\t';
		if (skill.getLevel(4) )
			cout << "4技能：" << skill.getName(4) << ends << skill.getLevel(4) << "点" << '\t';
		return true;
	}
	else {
		cout << "你当前尚未习得任何技能。" << endl;
		return false;
	}
}
double Role::useSkill() {
	if (showSkill() == false)
		return 0;
	else {
		cout << endl << "请选择：";
		int useWhatSkill;
		cin >> useWhatSkill;
		if (skill.getLevel(useWhatSkill) <= 0) {
			cout << "你尚未习得该技能，无法使用。" << endl;
			return 0;
		}
		else if (getMagic() < skill.getNeedMP(useWhatSkill)) {
			cout << "你的蓝量不足，无法使用该技能。" << endl;
			return 0;
		}
		else {
			cout << "你使用了“" << skill.getName(useWhatSkill) << "”技能，对";			//这里跳转回Filght.cpp继续
			return skill.getAddAttack(useWhatSkill) * skill.getLevel(useWhatSkill) * 0.1;//返回技能的攻击加成与技能等级提供的攻击加成
		}
	}
}

Role::~Role() {}

string Role::getName() {
	return name;
}

int Role::getType() {
	return type;
}

int Role::getMapId() {
	return mapId;
}

void Role::setMapId(int NewMapId) {
	mapId = NewMapId;
}

int Role::getHealth_max() {
	return health_max;
}

void Role::setHealth_max(int hp_m) {
	health_max = hp_m;
}

int Role::getHealth() {
	return health;
}

void Role::setHealth(int hp) {
	health = hp;
}

int Role::getMagic_max() {
	return magic_max;
}

void Role::setMagic_max(int mp_m) {
	magic_max = mp_m;

}

int Role::getMagic() {
	return magic;
}

void Role::setMagic(int mp) {
	magic = mp;

}

int Role::getAttack() {
	return attack;
}

void Role::setAttack(int a) {
	attack = a;

}

int Role::getDefend() {
	return defend;
}

void Role::setDefend(int d) {
	defend = d;
}

int Role::getExp() {
	return exp;
}

void Role::setExp(int e) {
	exp = e;
	for (int i = 0;i < 29;i++)
		if (exp >= levelExp_Max[i] && exp < levelExp_Max[i + 1]) {
			setLevel(i);
			setHealth_max(getHealth() *(1 + levelExp_Max[i] / 300));
			setMagic_max(getHealth() *(1 + levelExp_Max[i] / 300));
		}
	/*
	//每次增加经验，判断是否升级，暂定待优化
	if (getExp() > getExp_max()*0.02) {
		setHealth_max((int)getHealth_max() * 1.02);
		setMagic_max(getMagic_max() * 1.02);
		setLevel(2);
	}
	if (getExp() > getExp_max()*0.04) {
		setHealth_max((int)getHealth_max() * 1.04);
		setMagic_max(getMagic_max() * 1.04);
		setLevel(3);
	}
	if (getExp() > getExp_max()*0.06) {
		setHealth_max((int)getHealth_max() * 1.06);
		setMagic_max(getMagic_max() * 1.06);
		setLevel(4);
	}
	if (getExp() > getExp_max()*0.08) {
		setHealth_max((int)getHealth_max() * 1.08);
		setMagic_max(getMagic_max() * 1.08);
		setLevel(5);
	}
	if (getExp() > getExp_max()*0.10) {
		setHealth_max((int)getHealth_max() * 1.1);
		setMagic_max(getMagic_max() * 1.1);
		setLevel(6);
	}
	if (getExp() > getExp_max()*0.12) {
		setHealth_max((int)getHealth_max() * 1.12);
		setMagic_max(getMagic_max() * 1.12);
		setLevel(7);
	}
	if (getExp() > getExp_max()*0.14) {
		setHealth_max((int)getHealth_max() * 1.14);
		setMagic_max(getMagic_max() * 1.14);
		setLevel(8);
	}
	if (getExp() > getExp_max()*0.16) {
		setHealth_max((int)getHealth_max() * 1.16);
		setMagic_max(getMagic_max() * 1.16);
		setLevel(9);
	}
	if (getExp() > getExp_max()*0.18) {
		setHealth_max((int)getHealth_max() * 1.18);
		setMagic_max(getMagic_max() * 1.18);
		setLevel(10);
	}
	if (getExp() > getExp_max()*0.20) {
		setHealth_max((int)getHealth_max() * 1.20);
		setMagic_max(getMagic_max() * 1.20);
		setLevel(11);
	}
	//以上是2，以下是3
	if (getExp() > getExp_max()*0.23) {
		setHealth_max((int)getHealth_max() * 1.23);
		setMagic_max(getMagic_max() * 1.23);
		setLevel(12);
	}
	if (getExp() > getExp_max()*0.26) {
		setHealth_max((int)getHealth_max() * 1.26);
		setMagic_max(getMagic_max() * 1.26);
		setLevel(13);
	}
	if (getExp() > getExp_max()*0.29) {
		setHealth_max((int)getHealth_max() * 1.29);
		setMagic_max(getMagic_max() * 1.29);
		setLevel(14);
	}
	if (getExp() > getExp_max()*0.32) {
		setHealth_max((int)getHealth_max() * 1.32);
		setMagic_max(getMagic_max() * 1.32);
		setLevel(15);
	}
	if (getExp() > getExp_max()*0.35) {
		setHealth_max((int)getHealth_max() * 1.35);
		setMagic_max(getMagic_max() * 1.35);
		setLevel(16);
	}
	if (getExp() > getExp_max()*0.38) {
		setHealth_max((int)getHealth_max() * 1.38);
		setMagic_max(getMagic_max() * 1.38);
		setLevel(17);
	}
	if (getExp() > getExp_max()*0.41) {
		setHealth_max((int)getHealth_max() * 1.41);
		setMagic_max(getMagic_max() * 1.41);
		setLevel(18);
	}
	if (getExp() > getExp_max()*0.44) {
		setHealth_max((int)getHealth_max() * 1.44);
		setMagic_max(getMagic_max() * 1.44);
		setLevel(19);
	}
	if (getExp() > getExp_max()*0.47) {
		setHealth_max((int)getHealth_max() * 1.47);
		setMagic_max(getMagic_max() * 1.47);
		setLevel(20);
	}
	if (getExp() > getExp_max()*0.50) {
		setHealth_max((int)getHealth_max() * 1.50);
		setMagic_max(getMagic_max() * 1.5);
		setLevel(21);
	}
	if (getExp() > getExp_max()*0.54) {
		setHealth_max((int)getHealth_max() * 1.54);
		setMagic_max(getMagic_max() * 1.54);
		setLevel(22);
	}
	if (getExp() > getExp_max()*0.58) {
		setHealth_max((int)getHealth_max() * 1.58);
		setMagic_max(getMagic_max() * 1.58);
		setLevel(23);
	}
	if (getExp() > getExp_max()*0.62) {
		setHealth_max((int)getHealth_max() * 1.62);
		setMagic_max(getMagic_max() * 1.62);
		setLevel(24);
	}
	if (getExp() > getExp_max()*0.66) {
		setHealth_max((int)getHealth_max() * 1.66);
		setMagic_max(getMagic_max() * 1.66);
		setLevel(25);
	}
	if (getExp() > getExp_max()*0.70) {
		setHealth_max((int)getHealth_max() * 1.70);
		setMagic_max(getMagic_max() * 1.7);
		setLevel(26);
	}
	//以上是4，以下是5
	if (getExp() > getExp_max()*0.75) {
		setHealth_max((int)getHealth_max() * 1.75);
		setMagic_max(getMagic_max() * 1.75);
		setLevel(27);
	}
	if (getExp() > getExp_max()*0.80) {
		setHealth_max((int)getHealth_max() * 1.80);
		setMagic_max(getMagic_max() * 1.8);
		setLevel(28);
	}
	//以下是10
	if (getExp() > getExp_max()*0.90) {
		setHealth_max((int)getHealth_max() * 1.90);
		setMagic_max(getMagic_max() * 1.9);
		setLevel(29);
	}
	if (getExp() > getExp_max()) {
		setHealth_max((int)getHealth_max() * 2);
		setMagic_max(getMagic_max() * 2);
		setLevel(30);
	}
	return 0;
	*/
}

int Role::getLevelExp_max(int whichLevel) {
	return levelExp_Max[whichLevel];
}

int Role::getLevel() {
	return level;
}

void Role::setLevel(int l) {
	skillLevel = l - level;			//每次升级带来的技能升级点数
	for (; skillLevel > 0;) {
		cout << "你当前拥有" << skillLevel << "个技能点数，请选择要加点的技能：" << endl;

		for (int i = 1; i <= 4; i++)
			cout << i << "." << skill.getName(i) << '\t';
		cout << endl;
		int whatSkill;

		while (true) {
			cin >> whatSkill;
			if (whatSkill != 1 && whatSkill != 2 && whatSkill != 3 && whatSkill != 4)
				cout << "选择错误，请重新选择。" << endl;
			else break;
		}

		if (skill.addLevel(whatSkill) == true)
			skillLevel--;
	}
	level = l;
}

int Role::getMoney() {
	return money;
}

void Role::setMoney(int m) {
	money = m;
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

void Role::getBag() {
	bag.showBags();
}

bool Role::setBag(int goodsId, int num) {
	if (bag.getGoodsNum() > 20) {
		cout << "背包已满，无法添加。" << endl;
		return false;
	}
	else if (bag.getGoodsNum() + num > 20) {
		cout << "背包剩余空位不足，无法完全添加。" << endl;
		cout << "你仅能添加" << bag.getGoodsNum() + num - 20 << "件。" << endl;
		bag.addGoods(goodsId, bag.getGoodsNum() + num - 20);
		return true;
	}
	else {
		bag.addGoods(goodsId, num);
		return true;
	}
}