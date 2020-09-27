#ifndef FIGHTER_25_H
#define FIGHTER_25_H

#include "equipment.h"

class Fighter_25 : public Equipment { // 飘零之花手套
public:
	Fighter_25(){}
	void operator() (Character &model);
};

#endif // FIGHTER_25_H
