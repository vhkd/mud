#ifndef SKILL_H
#define SKILL_H

#include <String>
//#include "Role.h"
#include "Enemy.h"

class Skill {
public:
	Skill();
	~Skill() {};
	int getLevel(int whatSkill);		//判断技能等级（是否为零尚未习得）对应伤害
	bool addLevel(int whatSkill);	    //增加技能等级，每次一级
										//void setLevel(int whatSkill);		//设置技能等级

	int getLevel_Max(int whatSkill);	//得到技能的最高等级
	string getName(int whatSkill);		//得到技能名字
	string getDisc(int whatSkill);		//得到技能描述
	int getType(int whatSkill);			//得到技能类型
	int getNeedMP(int whatSkill);		//得到技能耗蓝
	double getAddAttack(int whatSkill);	//得到技能的攻击力加强
	int getRecoverHp(int whatSkill);	//得到技能恢复的生命值
	int getDebuff(int whatSkill);

	//void showRoleSkill();		//显示角色的所有技能

	//void enemyUseSkill(int whatSkill);		//怪物使用技能
	//void RoleUseSkill(int whatSkill);		//角色使用技能

protected:

	/*
	char disc[140];
	int skillLevel;
	int type;	//1,物理 2,法术 3,物法皆有
	int needMp;
	double addAttack;
	int recoverHp;
	int debuffSkill;
	*/

	string skill_1Name;
	string skill_2Name;
	string skill_3Name;
	string skill_4Name;

	string skill_1Disc;
	string skill_2Disc;
	string skill_3Disc;
	string skill_4Disc;

	int skill_1Level;			//在基类构造函数里初始化
	int skill_2Level;
	int skill_3Level;
	int skill_4Level;

	int skillLevel_Max_1;		//每个技能的最高等级
	int skillLevel_Max_2;		//在基类构造函数里初始化
	int skillLevel_Max_3;
	int skillLevel_Max_4;

	int skill_1Type;
	int skill_2Type;
	int skill_3Type;
	int skill_4Type;

	int skill_1NeedMp;
	int skill_2NeedMp;
	int skill_3NeedMp;
	int skill_4NeedMp;

	double skill_1AddAttack;
	double skill_2AddAttack;
	double skill_3AddAttack;
	double skill_4AddAttack;

	int skill_1recoverHp;
	int skill_2recoverHp;
	int skill_3recoverHp;
	int skill_4recoverHp;

	int skill_1debuffSkill;
	int skill_2debuffSkill;
	int skill_3debuffSkill;
	int skill_4debuffSkill;

};

//角色一的技能
class Role_1Skill :public Skill {
public:
	Role_1Skill() {
		skill_1Name = "基本枪棍";
		skill_2Name = "独孤九剑";
		skill_3Name = "疯魔杖法";
		skill_4Name = "四象掌";
		skill_1Disc = "长兵器的入门功夫，虽然普通，也能让你更强壮";
		skill_2Disc = "这大概是最厉害的剑法了，习得此剑，当可独步天下";
		skill_3Disc = "少林疯僧自创的杖法，能显著提升身法";
		skill_4Disc = "峨嵋入门掌法。提升内力的效果明显";

		skill_1Type = 1;
		skill_2Type = 1;
		skill_3Type = 2;
		skill_4Type = 3;

		skill_1NeedMp = 5;
		skill_2NeedMp = 10;
		skill_3NeedMp = 15;
		skill_4NeedMp = 25;

		skill_1AddAttack = 0.1;
		skill_1AddAttack = 0.15;
		skill_1AddAttack = 0;
		skill_1AddAttack = 0.5;

		skill_1recoverHp = 10;
		skill_2recoverHp = 15;
		skill_3recoverHp = 0;
		skill_4recoverHp = 20;

		skill_1debuffSkill = 0;
		skill_2debuffSkill = 0;
		skill_3debuffSkill = 15;
		skill_4debuffSkill = 20;
	}

private:

};

//角色二的技能,待设计
class Role_2Skill :public Skill {
public:
	Role_2Skill() {
		skill_1Name = "基本枪棍";
		skill_2Name = "独孤九剑";
		skill_3Name = "疯魔杖法";
		skill_4Name = "四象掌";

		skill_1Disc = "长兵器的入门功夫，虽然普通，也能让你更强壮。";
		skill_2Disc = "这大概是最厉害的剑法了，习得此剑，当可独步天下。";
		skill_3Disc = "少林疯僧自创的杖法，能显著提升身法。";
		skill_4Disc = "峨嵋入门掌法。提升内力的效果明显。";

		skill_1Type = 1;
		skill_2Type = 1;
		skill_3Type = 2;
		skill_4Type = 3;

		skill_1NeedMp = 5;
		skill_2NeedMp = 10;
		skill_3NeedMp = 15;
		skill_4NeedMp = 25;

		skill_1AddAttack = 0.1;
		skill_1AddAttack = 0.15;
		skill_1AddAttack = 0;
		skill_1AddAttack = 0.5;

		skill_1recoverHp = 10;
		skill_2recoverHp = 15;
		skill_3recoverHp = 0;
		skill_4recoverHp = 20;

		skill_1debuffSkill = 0;
		skill_2debuffSkill = 0;
		skill_3debuffSkill = 15;
		skill_4debuffSkill = 20;
	}
private:

};

//角色三的技能，待设计
class Role_3Skill :public Skill {
public:
	Role_3Skill() {
		skill_1Name = "基本枪棍";
		skill_2Name = "独孤九剑";
		skill_3Name = "疯魔杖法";
		skill_4Name = "四象掌";

		skill_1Disc = "长兵器的入门功夫，虽然普通，也能让你更强壮。";
		skill_2Disc = "这大概是最厉害的剑法了，习得此剑，当可独步天下。";
		skill_3Disc = "少林疯僧自创的杖法，能显著提升身法。";
		skill_4Disc = "峨嵋入门掌法。提升内力的效果明显。";

		skill_1Type = 1;
		skill_2Type = 1;
		skill_3Type = 2;
		skill_4Type = 3;

		skill_1NeedMp = 5;
		skill_2NeedMp = 10;
		skill_3NeedMp = 15;
		skill_4NeedMp = 25;

		skill_1AddAttack = 0.1;
		skill_1AddAttack = 0.15;
		skill_1AddAttack = 0;
		skill_1AddAttack = 0.5;

		skill_1recoverHp = 10;
		skill_2recoverHp = 15;
		skill_3recoverHp = 0;
		skill_4recoverHp = 20;

		skill_1debuffSkill = 0;
		skill_2debuffSkill = 0;
		skill_3debuffSkill = 15;
		skill_4debuffSkill = 20;
	}
private:

};

#endif