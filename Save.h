#ifndef SAVE_H
#define SAVE_H
#include"Role.h"

class Save {
public:
	Save(Role player);
	~Save();

private:
	Role player;
};

#endif