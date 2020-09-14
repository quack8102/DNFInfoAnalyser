#ifndef FIGHTER_14_H
#define FIGHTER_14_H

#include "equipment.h"

class Fighter_14 : public Equipment { // 痛苦之源 Fighter: 5
  public:
    Fighter_14() {}
	void operator() (Character &model);
};

#endif // FIGHTER_14_H
