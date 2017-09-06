#include "Bag.h"

Bag::Bag()
{
	int bagsMax = 20;//
	for (int i = 0; i < bagsMax; i++)
	{
		bags[i] = 0;
	}
}

Bag::~Bag()
{
}

void Bag::showBags()
{
	cout << "��ǰ����:" << endl;
	cout << "��Ʒ����      ����" << endl;
	map<int, int>::iterator iter;
	for (iter = bags.begin(); iter != bags.end(); ++iter)
	{
		cout << goods[iter->first].getName() << iter->second << endl;
	}
}

void Bag::addGoods(int id, int num)
{
	if(bags.count(id))
	{
		bags[id] += num;
	}
	else
	{
		bags.insert(pair<int, int>(id, num));
	}
}

void Bag::reduceGoods(int id, int num)
{
	bags[id] -= num;
	if (bags[id] <= 0)
	{
		bags.erase(id);
	}
}
