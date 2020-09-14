#ifndef FIGHTER_12_H
#define FIGHTER_12_H

#include "equipment.h"

class Fighter_12 : public Equipment { // 暗黑圣战之溯回：爪 Fighter: 5
  public:
    Fighter_12() {}
	void operator() (Character &model);
};

#endif // FIGHTER_12_H
