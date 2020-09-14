#ifndef FIGHTER_2_H
#define FIGHTER_2_H

#include "equipment.h"

class Fighter_2 : public Equipment { // 暗黑圣战之溯回：手套 Fighter: 5
  public:
    Fighter_2() {}
	void operator() (Character &model);
};

#endif // FIGHTER_2_H
