#ifndef FIGHTER_4_H
#define FIGHTER_4_H

#include "equipment.h"

class Fighter_4 : public Equipment { // 无瑕之意志手套 Fighter: 5
  public:
    Fighter_4() {}
	void operator() (Character &model);
};

#endif // FIGHTER_4_H
