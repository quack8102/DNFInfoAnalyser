#ifndef FIGHTER_27_H
#define FIGHTER_27_H

#include "equipment.h"

class Fighter_27 : public Equipment { // 飘零之花利爪
public:
	Fighter_27(){}
	void operator() (Character &model);
};

#endif // FIGHTER_27_H
