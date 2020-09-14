#ifndef FIGHTER_6_H
#define FIGHTER_6_H

#include "equipment.h"

class Fighter_6 : public Equipment { // 界·夜语黑瞳臂铠 Fighter: 5
  public:
    Fighter_6() {}
	void operator() (Character &model);
};

#endif // FIGHTER_6_H
