#ifndef FIGHTER_13_H
#define FIGHTER_13_H

#include "equipment.h"

class Fighter_13 : public Equipment { // 疯狂飓风 Fighter: 5
  public:
    Fighter_13() {}
	void operator() (Character &model);
};

#endif // FIGHTER_13_H
