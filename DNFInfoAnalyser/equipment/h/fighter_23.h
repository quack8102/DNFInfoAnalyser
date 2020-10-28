#ifndef FIGHTER_23_H
#define FIGHTER_23_H

#include "equipment.h"

class Fighter_23 : public Equipment { // 青沙棍 Fighter: 5
  public:
    Fighter_23() {}
	void operator() (Character &model);
};

#endif // FIGHTER_23_H
