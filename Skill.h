class Skill
{
public:
	Skill();
	~Skill();
	
private:
	string name;
	string disc;
	int skillLevel = 0;
	int type;
	int needMp;
	double addAttack;
	int recoverHp=0;
	int debuffSkill;
}
