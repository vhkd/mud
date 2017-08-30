class Skill
{
public:
	Skill();
	~Skill();
	
private:
	char name[20];
	char disc[140];
	int skillLevel = 0;
	int type;
	int needMp;
	double addAttack;
	int recoverHp=0;
	int debuffSkill;
};