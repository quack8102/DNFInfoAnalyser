#ifndef FIGHTER_17_H
#define FIGHTER_17_H

#include "equipment.h"

class Fighter_17 : public Equipment { // 暗黑圣战之溯回：拳套 Fighter: 5
  public:
    Fighter_17() {}
	void operator() (Character &model);
};

#endif // FIGHTER_17_H
