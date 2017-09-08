#include <iostream>
#include <string>
#include <vector>
#include "Store.h"

using namespace std;

Store::Store()
{
	for (int i = 0; i < 24; ++i)
	{
		stores.insert(pair<int, int>(i, 999));//商店物品初始化 数量为999
	}
	
}

Store::~Store()
{
}

void Store::showStores()
{
	cout << "物品" << "描述" << "价格" << endl;
	map<int, int>::iterator iter;
	for (iter = stores.begin(); iter != stores.end(); ++iter)
	{
		cout << goods[iter->first].getName() << goods[iter->first].getDesc() << goods[iter->first].getPriceBuy() << endl;
	}
}

void Store::storeToPlayer(Role player, Bag bags)
{
	int goodsId, goodsNum;
	cout << "请输入要购买的物品序号" << endl;
	cin >> goodsId;
	cout << "请输入要购买的数量" << endl;
	cin >> goodsNum;
	int totalPrice = int(goods[goodsId].getPriceBuy()) * int(goodsNum);
	if (player.getMoney() >= totalPrice)
	{
		bags.addGoods(goodsId, goodsNum);
		player.setMoney(player.getMoney() - totalPrice);
		cout << "购买成功" << endl;
	}
	else
	{
		cout << "金钱不足,购买失败" << endl;
	}
}

void Store::playerToStore(Role player, Bag bags)
{
	int goodsId, goodsNum;
	cout << "请输入要卖出的物品序号" << endl;
	cin >> goodsId;
	cout << "请输入要卖出的数量" << endl;
	cin >> goodsNum;
	int totalPrice = int(goods[goodsId].getPriceSell()) * int(goodsNum);
	bags.reduceGoods(goodsId, goodsNum);
	player.setMoney(player.getMoney() + totalPrice);
	cout << "出售成功" << endl;
}
