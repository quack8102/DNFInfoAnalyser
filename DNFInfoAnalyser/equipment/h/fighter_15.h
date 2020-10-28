#ifndef FIGHTER_15_H
#define FIGHTER_15_H

#include "equipment.h"

class Fighter_15 : public Equipment { // 夜语黑瞳拳套 Fighter: 5
  public:
    Fighter_15() {}
	void operator() (Character &model);
};

#endif // FIGHTER_15_H
