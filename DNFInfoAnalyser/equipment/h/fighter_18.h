#ifndef FIGHTER_18_H
#define FIGHTER_18_H

#include "equipment.h"

class Fighter_18 : public Equipment { // 猎焰追魂拳套 Fighter: 5
  public:
    Fighter_18() {}
	void operator() (Character &model);
};

#endif // FIGHTER_18_H
