#ifndef STORE_SYSTEM_H
#define STORE_SYSTEM_H

#include "domain/Role.h"

class StoreSystem {
public:
	void run(Role &player) const;

private:
	void showCatalog() const;
	void buy(Role &player) const;
	void sell(Role &player) const;
	int readChoice(int min, int max) const;
};

#endif
