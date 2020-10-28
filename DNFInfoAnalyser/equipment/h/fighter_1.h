#ifndef FIGHTER_1_H
#define FIGHTER_1_H

#include "equipment.h"

class Fighter_1 : public Equipment { // 界·夜语黑瞳手套 Fighter: 5
  public:
    Fighter_1() {}
	void operator() (Character &model);
};

#endif // FIGHTER_1_H
