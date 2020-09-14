#ifndef FIGHTER_24_H
#define FIGHTER_24_H

#include "equipment.h"

class Fighter_24 : public Equipment { // 鸣鸿破影棍 Fighter: 5
  public:
    Fighter_24() {}
	void operator() (Character &model);
};

#endif // FIGHTER_24_H
