#ifndef FIGHTER_7_H
#define FIGHTER_7_H

#include "equipment.h"

class Fighter_7 : public Equipment { // 暗黑圣战之溯回：臂铠 Fighter: 5
  public:
    Fighter_7() {}
	void operator() (Character &model);
};

#endif // FIGHTER_7_H
