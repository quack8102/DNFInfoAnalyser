#ifndef FIGHTER_8_H
#define FIGHTER_8_H

#include "equipment.h"

class Fighter_8 : public Equipment { // 太阴神：灵龟 Fighter: 5
  public:
    Fighter_8() {}
	void operator() (Character &model);
};

#endif // FIGHTER_8_H
