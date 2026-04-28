#ifndef SAVE_H
#define SAVE_H
#include "domain/Role.h"

class Save {
public:
	static bool setToFile(const Role &player);
	static bool loadFromFile(Role &player);
};

#endif
