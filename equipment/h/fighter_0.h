#ifndef FIGHTER_0_H
#define FIGHTER_0_H

#include "equipment.h"

class Fighter_0 : public Equipment { // 夜语黑瞳手套 Fighter: 5
  public:
    Fighter_0() {}
	void operator() (Character &model);
};

#endif // FIGHTER_0_H
