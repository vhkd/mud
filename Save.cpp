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
		cout << "�޷��򿪱����ļ���" << endl;
		return;
	}
	else if (file.write(reinterpret_cast<char *>(&player), sizeof(Role)))
		cout << "����ɹ���" << endl;
	else cout << "δ�ܱ��棡" << endl;
	file.close();
}

#endif