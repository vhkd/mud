#ifndef SAVE_CPP
#define SAVE_CPP
#include"Save.h"
#include<fstream>
#include<iostream>
using namespace std;

void Save::setToFile(Role player) {
	ofstream file("Save.dat", ios_base::binary);
	if (!file) {
		cout << "�޷��򿪱����ļ���" << endl;
		cout << "����ʧ�ܣ�" << endl;
	}
	else if (file.write(reinterpret_cast<char *>(&player), sizeof(player)))
		cout << "����ɹ���" << endl;
	else cout << "δ�ܱ��棡" << endl;
	file.close();
}

#endif


