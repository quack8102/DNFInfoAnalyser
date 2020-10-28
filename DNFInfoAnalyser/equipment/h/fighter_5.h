#ifndef FIGHTER_5_H
#define FIGHTER_5_H

#include "equipment.h"

class Fighter_5 : public Equipment { // 夜语黑瞳臂铠 Fighter: 5
  public:
    Fighter_5() {}
	void operator() (Character &model);
};

#endif // FIGHTER_5_H
