#ifndef FIGHTER_26_H
#define FIGHTER_26_H

#include "equipment.h"

class Fighter_26 : public Equipment { // 飘零之花臂铠
public:
	Fighter_26(){}
	void operator() (Character &model);
};

#endif // FIGHTER_26_H
