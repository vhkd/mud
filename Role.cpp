#include <iostream>
#include <string>
#include "Role.h"

using namespace std;

Role::Role(int t)//1战士2剑客3法师
{
	switch (t) {
	case '1': {
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
	case '2': {
		name = "22222";
		type = 2;
		health_max = 200;
		health = 200;
		magic_max = 100;
		magic = 100;
		attack = 30;
		exp = 0;
		exp_Max = 350;			//暂定
		level = 1;
		defend = 20;
		money = 0;
		skill = Role_2Skill::Role_2Skill();
		break;
	}
	case '3': {
		name = "33333";
		type = 3;
		health_max = 120;
		health = 120;
		magic_max = 100;
		magic = 100;
		attack = 45;
		exp = 0;
		exp_Max = 400;				//暂定
		level = 1;
		defend = 10;
		money = 0;
		skill = Role_3Skill::Role_3Skill();
		break;
	}
	default:
		break;
	}
}

bool Role::showSkill() {    //返回是否有技能释放
	if (skill.getLevel(1) == 0 && skill.getLevel(2) == 0 && skill.getLevel(3) == 0 && skill.getLevel(4) == 0) {
		cout << "你当前尚未习得任何技能。" << endl;
		return false;
	}
	else {
		cout << "你可以选择使用的技能有：" << endl;
		if (skill.getLevel(1) > 0)
			cout << "1技能：" << skill.getName(1) << ends << skill.getLevel(1) << "点" << '\t';
		if (skill.getLevel(2) > 0)
			cout << "2技能：" << skill.getName(2) << ends << skill.getLevel(2) << "点" << '\t';
		if (skill.getLevel(3) > 0)
			cout << "3技能：" << skill.getName(3) << ends << skill.getLevel(3) << "点" << '\t';
		if (skill.getLevel(4) > 0)
			cout << "4技能：" << skill.getName(4) << ends << skill.getLevel(4) << "点" << '\t';
		return true;
	}
}
double Role::useSkill() {
	if (showSkill() == false)
		return 0;
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

Role::~Role() {}

string Role::getName() {
	return name;
}

int Role::getType() {
	return type;
}

int Role::getHealth_max() {
	return health_max;
}

int Role::setHealth_max(int hp_m) {
	health_max = hp_m;
	return 0;
}

int Role::getHealth() {
	return health;
}

int Role::setHealth(int hp) {
	health = hp;
	return 0;
}

int Role::getMagic_max() {
	return magic_max;
}

int Role::setMagic_max(int mp_m) {
	magic_max = mp_m;
	return 0;
}

int Role::getMagic() {
	return magic;
}

int Role::setMagic(int mp) {
	magic = mp;
	return 0;
}

int Role::getAttack() {
	return attack;
}

int Role::setAttack(int a) {
	attack = a;
	return 0;
}

int Role::getDefend() {
	return defend;
}

int Role::setDefend(int d) {
	defend = d;
	return 0;
}

int Role::getExp() {
	return exp;
}

int Role::setExp(int e) {
	exp = e;

	//每次增加经验，判断是否升级，暂定待优化
	if (getExp() > getExp_max()*0.02) {
		setHealth_max(getHealth_max() * 1.02);
		setMagic_max(getMagic_max() * 1.02);
		setLevel(2);
	}
	if (getExp() > getExp_max()*0.04) {
		setHealth_max(getHealth_max() * 1.04);
		setMagic_max(getMagic_max() * 1.04);
		setLevel(3);
	}
	if (getExp() > getExp_max()*0.06) {
		setHealth_max(getHealth_max() * 1.06);
		setMagic_max(getMagic_max() * 1.06);
		setLevel(4);
	}
	if (getExp() > getExp_max()*0.08) {
		setHealth_max(getHealth_max() * 1.08);
		setMagic_max(getMagic_max() * 1.08);
		setLevel(5);
	}
	if (getExp() > getExp_max()*0.10) {
		setHealth_max(getHealth_max() * 1.1);
		setMagic_max(getMagic_max() * 1.1);
		setLevel(6);
	}
	if (getExp() > getExp_max()*0.12) {
		setHealth_max(getHealth_max() * 1.12);
		setMagic_max(getMagic_max() * 1.12);
		setLevel(7);
	}
	if (getExp() > getExp_max()*0.14) {
		setHealth_max(getHealth_max() * 1.14);
		setMagic_max(getMagic_max() * 1.14);
		setLevel(8);
	}
	if (getExp() > getExp_max()*0.16) {
		setHealth_max(getHealth_max() * 1.16);
		setMagic_max(getMagic_max() * 1.16);
		setLevel(9);
	}
	if (getExp() > getExp_max()*0.18) {
		setHealth_max(getHealth_max() * 1.18);
		setMagic_max(getMagic_max() * 1.18);
		setLevel(10);
	}
	if (getExp() > getExp_max()*0.20) {
		setHealth_max(getHealth_max() * 1.20);
		setMagic_max(getMagic_max() * 1.20);
		setLevel(11);
	}
	//以上是2，以下是3
	if (getExp() > getExp_max()*0.23) {
		setHealth_max(getHealth_max() * 1.23);
		setMagic_max(getMagic_max() * 1.23);
		setLevel(12);
	}
	if (getExp() > getExp_max()*0.26) {
		setHealth_max(getHealth_max() * 1.26);
		setMagic_max(getMagic_max() * 1.26);
		setLevel(13);
	}
	if (getExp() > getExp_max()*0.29) {
		setHealth_max(getHealth_max() * 1.29);
		setMagic_max(getMagic_max() * 1.29);
		setLevel(14);
	}
	if (getExp() > getExp_max()*0.32) {
		setHealth_max(getHealth_max() * 1.32);
		setMagic_max(getMagic_max() * 1.32);
		setLevel(15);
	}
	if (getExp() > getExp_max()*0.35) {
		setHealth_max(getHealth_max() * 1.35);
		setMagic_max(getMagic_max() * 1.35);
		setLevel(16);
	}
	if (getExp() > getExp_max()*0.38) {
		setHealth_max(getHealth_max() * 1.38);
		setMagic_max(getMagic_max() * 1.38);
		setLevel(17);
	}
	if (getExp() > getExp_max()*0.41) {
		setHealth_max(getHealth_max() * 1.41);
		setMagic_max(getMagic_max() * 1.41);
		setLevel(18);
	}
	if (getExp() > getExp_max()*0.44) {
		setHealth_max(getHealth_max() * 1.44);
		setMagic_max(getMagic_max() * 1.44);
		setLevel(19);
	}
	if (getExp() > getExp_max()*0.47) {
		setHealth_max(getHealth_max() * 1.47);
		setMagic_max(getMagic_max() * 1.47);
		setLevel(20);
	}
	if (getExp() > getExp_max()*0.50) {
		setHealth_max(getHealth_max() * 1.50);
		setMagic_max(getMagic_max() * 1.5);
		setLevel(21);
	}
	if (getExp() > getExp_max()*0.54) {
		setHealth_max(getHealth_max() * 1.54);
		setMagic_max(getMagic_max() * 1.54);
		setLevel(22);
	}
	if (getExp() > getExp_max()*0.58) {
		setHealth_max(getHealth_max() * 1.58);
		setMagic_max(getMagic_max() * 1.58);
		setLevel(23);
	}
	if (getExp() > getExp_max()*0.62) {
		setHealth_max(getHealth_max() * 1.62);
		setMagic_max(getMagic_max() * 1.62);
		setLevel(24);
	}
	if (getExp() > getExp_max()*0.66) {
		setHealth_max(getHealth_max() * 1.66);
		setMagic_max(getMagic_max() * 1.66);
		setLevel(25);
	}
	if (getExp() > getExp_max()*0.70) {
		setHealth_max(getHealth_max() * 1.70);
		setMagic_max(getMagic_max() * 1.7);
		setLevel(26);
	}
	//以上是4，以下是5
	if (getExp() > getExp_max()*0.75) {
		setHealth_max(getHealth_max() * 1.75);
		setMagic_max(getMagic_max() * 1.75);
		setLevel(27);
	}
	if (getExp() > getExp_max()*0.80) {
		setHealth_max(getHealth_max() * 1.80);
		setMagic_max(getMagic_max() * 1.8);
		setLevel(28);
	}
	//以下是10
	if (getExp() > getExp_max()*0.90) {
		setHealth_max(getHealth_max() * 1.90);
		setMagic_max(getMagic_max() * 1.9);
		setLevel(29);
	}
	if (getExp() > getExp_max()) {
		setHealth_max(getHealth_max() * 2);
		setMagic_max(getMagic_max() * 2);
		setLevel(30);
	}
	return 0;
}

int Role::getExp_max() {
	return exp_Max;
}

int Role::getLevel() {
	return level;
}

int Role::setLevel(int l) {
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
	health_Max =
		return 0;
}

int Role::getMoney() {
	return money;
}

int Role::setMoney(int m) {
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

void Role::getBag() {
}

bool Role::setBag(int goodsId) {

}