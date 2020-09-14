#ifndef FIGHTER_19_H
#define FIGHTER_19_H

#include "equipment.h"

class Fighter_19 : public Equipment { // 幻光绽放拳套 Fighter: 5
  public:
    Fighter_19() {}
	void operator() (Character &model);
};

#endif // FIGHTER_19_H
