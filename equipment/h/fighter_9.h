#ifndef FIGHTER_9_H
#define FIGHTER_9_H

#include "equipment.h"

class Fighter_9 : public Equipment { // 毁灭之碾压 Fighter: 5
  public:
    Fighter_9() {}
	void operator() (Character &model);
};

#endif // FIGHTER_9_H
