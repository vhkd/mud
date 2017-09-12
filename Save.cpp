#ifndef SAVE_CPP
#define SAVE_CPP
#include"Save.h"
#include<fstream>
#include<iostream>
using namespace std;

void Save::setToFile(Role player) {
	ofstream file("Save.dat", ios_base::binary);
	if (!file) {
		cout << "无法打开保存文件！" << endl;
		cout << "保存失败！" << endl;
	}
	else if (file.write(reinterpret_cast<char *>(&player), sizeof(player)))
		cout << "保存成功！" << endl;
	else cout << "未能保存！" << endl;
	file.close();
}

#endif


