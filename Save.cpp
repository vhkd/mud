#ifndef SAVE_CPP
#define SAVE_CPP
#include"Save.h"
#include<fstream>
#include<iostream>
using namespace std;

void Save::setToFile(Role player) {
	ofstream file1("SaveRole.txt", ios_base::binary);
	ofstream file2("SaveBag.txt", ios_base::binary);
	if (!file1 || !file2) {
		cout << "无法打开保存文件！" << endl;
		cout << "保存失败！" << endl;
	}
	else 
	{
		file1 << player.getName() << ' '
			<< player.getType() << ' '
			<< player.getHealth_max() << ' '
			<< player.getHealth() << ' '
			<< player.getMagic() << ' '
			<< player.getMagic_max() << ' '
			<< player.getAttack() << ' '
			<< player.getExp() << ' '
			<< player.getLevel() << ' '
			<< player.getDefend() << ' '
			<< player.getMoney() << ' '
			<< player.getMapId() << ' '
			<< player.getStory() << ' ';

		for (const auto &i : player.getBag().getMapBags()) {
			file2 << i.first << ' ' << i.second << " ";
		}
	}
	file1.close();
	file2.close();
}

#endif


