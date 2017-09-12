#include "Read.h"
#include <iostream>
#include <fstream>
using namespace std;

Read::Read(int roleType) :player(roleType) {}

Role Read::getRole() {			//读取人物属性

	ifstream file("Save.dat", ios_base::in | ios_base::binary);
	file.read(reinterpret_cast<char *>(&player), sizeof(player));
	cout << "*****name = " << player.getName() << endl;
	/*
	if (!file) {
		cout << "没有保存的游戏！" << endl;
		return player;
	}
	else if (file.read(reinterpret_cast<char *>(&player), sizeof(player))) {
		cout << "读入成功！" << endl;
		return player;
	}
	else {
		cout << "读入失败！" << endl;
		return player;
	}

	*/
	file.close();
}