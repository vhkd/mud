#include "Read.h"
#include <iostream>
#include <fstream>
using namespace std;

Read::Read(int roleType) :player(roleType) {}

Role Read::getRole() {			//��ȡ��������

	ifstream file("Save.dat", ios_base::in | ios_base::binary);
	file.read(reinterpret_cast<char *>(&player), sizeof(player));
	cout << "*****name = " << player.getName() << endl;
	/*
	if (!file) {
		cout << "û�б������Ϸ��" << endl;
		return player;
	}
	else if (file.read(reinterpret_cast<char *>(&player), sizeof(player))) {
		cout << "����ɹ���" << endl;
		return player;
	}
	else {
		cout << "����ʧ�ܣ�" << endl;
		return player;
	}

	*/
	file.close();
}