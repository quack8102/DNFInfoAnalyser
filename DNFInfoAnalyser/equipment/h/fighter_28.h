#ifndef FIGHTER_28_H
#define FIGHTER_28_H

#include "equipment.h"

class Fighter_28 : public Equipment { // 飘零之花拳套
public:
	Fighter_28(){}
	void operator() (Character &model);
};

#endif // FIGHTER_28_H
