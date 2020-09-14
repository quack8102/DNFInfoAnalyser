#ifndef FIGHTER_22_H
#define FIGHTER_22_H

#include "equipment.h"

class Fighter_22 : public Equipment { // 暗黑圣战之溯回：东方棍 Fighter: 5
  public:
    Fighter_22() {}
	void operator() (Character &model);
};

#endif // FIGHTER_22_H
