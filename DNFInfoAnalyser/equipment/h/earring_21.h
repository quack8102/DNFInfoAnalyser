#ifndef EARRING_21_H
#define EARRING_21_H

#include "equipment.h"

class Earring_21 : public Equipment { // 无我灵晶
public:
	Earring_21(){}
	void operator() (Character &model);
};

#endif // EARRING_21_H
