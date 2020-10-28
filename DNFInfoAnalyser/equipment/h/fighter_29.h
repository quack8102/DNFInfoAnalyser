#ifndef FIGHTER_29_H
#define FIGHTER_29_H

#include "equipment.h"

class Fighter_29 : public Equipment { // 飘零之花东方棍
public:
	Fighter_29(){}
	void operator() (Character &model);
};

#endif // FIGHTER_29_H
