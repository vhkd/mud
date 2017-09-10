
#ifndef READ_H
#define READ_H

#include"Role.h"

class Read {

public:
	Read(int roleType);
	~Read();
	Role getRole();
private:
	Role player;
};

#endif