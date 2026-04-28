#include "systems/StoreSystem.h"

#include <cstdlib>
#include <iomanip>
#include <iostream>

#include "io/Console.h"
#include "domain/Goods.h"

using namespace std;

void StoreSystem::run(Role &player) const {
	cout << "1.购买物品 2.售出物品 3.退出" << endl;
	const int choice = readChoice(1, 3);
	if (choice == 1) {
		buy(player);
	} else if (choice == 2) {
		sell(player);
	}
	Console::pause();
}

void StoreSystem::showCatalog() const {
	Goods goods[24] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 };
	cout << left << setw(6) << "编号" << setw(14) << "物品" << setw(72) << "描述" << "价格" << endl;
	for (int i = 0; i < 24; i++) {
		cout << left << setw(6) << i
			<< setw(14) << goods[i].getName()
			<< setw(72) << goods[i].getDesc()
			<< goods[i].getPriceBuy() << endl;
	}
}

void StoreSystem::buy(Role &player) const {
	Goods goods[24] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 };
	showCatalog();
	cout << "请输入要购买的物品编号（24 退出）：" << endl;
	const int goodsId = readChoice(0, 24);
	if (goodsId == 24) {
		return;
	}

	cout << "请输入购买数量（0 退出）：" << endl;
	const int goodsNum = readChoice(0, 99);
	if (goodsNum == 0) {
		return;
	}

	const int totalPrice = goods[goodsId].getPriceBuy() * goodsNum;
	if (player.getMoney() < totalPrice) {
		cout << "银钱不够，这笔买卖做不成。" << endl;
		return;
	}

	player.addGoodsToBag(goodsId, goodsNum);
	player.setMoney(player.getMoney() - totalPrice);
	cout << "购买成功，获得 " << goods[goodsId].getName() << " x" << goodsNum << "。" << endl;
}

void StoreSystem::sell(Role &player) const {
	Goods goods[24] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 };
	player.showBag();
	cout << "请输入要卖出的物品编号（24 退出）：" << endl;
	const int goodsId = readChoice(0, 24);
	if (goodsId == 24) {
		return;
	}

	cout << "请输入卖出数量（0 退出）：" << endl;
	const int goodsNum = readChoice(0, 99);
	if (goodsNum == 0) {
		return;
	}

	if (!player.subGoodsToBag(goodsId, goodsNum)) {
		cout << "背包里没有这么多 " << goods[goodsId].getName() << "。" << endl;
		return;
	}

	const int totalPrice = goods[goodsId].getPriceSell() * goodsNum;
	player.setMoney(player.getMoney() + totalPrice);
	cout << "售出成功，获得 " << totalPrice << " 点金钱。" << endl;
}

int StoreSystem::readChoice(int min, int max) const {
	int choice = 0;
	while (true) {
		if ((cin >> choice) && choice >= min && choice <= max) {
			return choice;
		}
		if (cin.eof()) {
			std::exit(0);
		}
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "选择错误，请重新选择。" << endl;
	}
}
