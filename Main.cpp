#include <iostream>
#include "Bag.h"
#include "Enemy.h"
#include "Fight.h"
#include "Goods.h"
#include "Map.h"
#include "Npc.h"
#include "Role.h"
#include "Skill.h"
#include "Store.h"

using namespace std;

int initGame() 
{
	//���ﴴ��
	int choiceRole;
	cout << "������Ҫ������ְҵ 1...  2...  3..." << endl;
	cin >> choiceRole;
	Role player(choiceRole);
	cout << "�����ɹ�" << endl;

	Bag bags;

	Map_Total map_total;//�����ͼ
	Map_Separate map[9] = {1,2,3,4,5,6,7,8,9};//С��ͼ
}

int main()
{
	cout << "1.�µ���Ϸ  2.��ȡ�浵  3.�˳���Ϸ" << endl;
	int choice;
	switch (choice)
	{
	case '1':{
		initGame();
		break;
	}
	case '2': {
		//��ȡ�浵
		break;
	}
	case '3': {
		break;
	}
	default:
		break;
	}
}