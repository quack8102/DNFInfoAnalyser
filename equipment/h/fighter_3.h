#ifndef FIGHTER_3_H
#define FIGHTER_3_H

#include "equipment.h"

class Fighter_3 : public Equipment { // 白虎啸魂手套 Fighter: 5
  public:
    Fighter_3() {}
	void operator() (Character &model);
};

#endif // FIGHTER_3_H
