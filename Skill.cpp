#include <iostream>
#include "Skill.h"

using namespace std;

Skill::Skill() {
	skill_1Level = 0;
	skill_2Level = 0;
	skill_3Level = 0;
	skill_4Level = 0;
	skillLevel_Max_1 = 7;		//每个技能的最高等级,待定
	skillLevel_Max_2 = 7;
	skillLevel_Max_3 = 7;
	skillLevel_Max_4 = 6;

}
int Skill::getLevel(int whatSkill) {
	switch (whatSkill) {
	case '1':return skill_1Level; break;
	case '2':return skill_2Level; break;
	case '3':return skill_3Level; break;
	case '4':return skill_4Level; break;
	default:break;
	}
}

int Skill::getLevel_Max(int whatSkill) {
	switch (whatSkill) {
	case '1':return skillLevel_Max_1; break;
	case '2':return skillLevel_Max_2; break;
	case '3':return skillLevel_Max_3; break;
	case '4':return skillLevel_Max_4; break;
	default:break;
	}
}

string Skill::getName(int whatSkill) {
	switch (whatSkill) {
	case '1':return skill_1Name; break;
	case '2':return skill_2Name; break;
	case '3':return skill_3Name; break;
	case '4':return skill_4Name; break;
	default:break;
	}
}

string Skill::getDisc(int whatSkill) {
	switch (whatSkill) {
	case '1':return skill_1Disc; break;
	case '2':return skill_2Disc; break;
	case '3':return skill_3Disc; break;
	case '4':return skill_4Disc; break;
	default:break;
	}
}

int Skill::getType(int whatSkill) {
	switch (whatSkill) {
	case '1':return skill_1Type; break;
	case '2':return skill_2Type; break;
	case '3':return skill_3Type; break;
	case '4':return skill_4Type; break;
	default:break;
	}
}

int Skill::getNeedMP(int whatSkill) {
	switch (whatSkill) {
	case '1':return skill_1NeedMp; break;
	case '2':return skill_2NeedMp; break;
	case '3':return skill_3NeedMp; break;
	case '4':return skill_4NeedMp; break;
	default:break;
	}
}

double Skill::getAddAttack(int whatSkill) {
	switch (whatSkill) {
	case '1':return skill_1AddAttack; break;
	case '2':return skill_2AddAttack; break;
	case '3':return skill_3AddAttack; break;
	case '4':return skill_4AddAttack; break;
	default:break;
	}
}

int Skill::getRecoverHp(int whatSkill) {
	switch (whatSkill) {
	case '1':return skill_1recoverHp; break;
	case '2':return skill_2recoverHp; break;
	case '3':return skill_3recoverHp; break;
	case '4':return skill_4recoverHp; break;
	default:break;
	}
}
int Skill::getDebuff(int whatSkill) {
	switch (whatSkill) {
	case '1':return skill_1debuffSkill; break;
	case '2':return skill_2debuffSkill; break;
	case '3':return skill_3debuffSkill; break;
	case '4':return skill_4debuffSkill; break;
	default:break;
	}
}
bool Skill::addLevel(int whatSkill) {
	if (getLevel(whatSkill) >= getLevel_Max(whatSkill)) {
		cout << "技能等级已满，无法加点。";
		return false;
	}
	else {
		switch (whatSkill) {
		case '1':skill_1Level++;
		case '2':skill_2Level++;
		case '3':skill_3Level++;
		case '4':skill_4Level++;
		default:break;
		}
		cout << "成功添加一点！" << endl;
		return true;
	}
}
/*for(int i = 1;i <= 4;i++)
cout<<i<<"."<<getName(i)<<'\t';
cout<<endl;
*/
