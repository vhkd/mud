#ifndef SAVE_CPP
#define SAVE_CPP
#include"Save.h"
#include<fstream>
#include<iostream>
using namespace std;

Save::Save(Role player) :player(player) {
	ofstream file;
	file.open("Save.dat");
	if (!file) {
		cout << "无法打开保存文件！" << endl;
		return;
	}
	else if (file.write(reinterpret_cast<char *>(&player), sizeof(Role)))
		cout << "保存成功！" << endl;
	else cout << "未能保存！" << endl;
	file.close();
}

#endif