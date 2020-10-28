#ifndef FIGHTER_20_H
#define FIGHTER_20_H

#include "equipment.h"

class Fighter_20 : public Equipment { // 夜语黑瞳东方棍 Fighter: 5
  public:
    Fighter_20() {}
	void operator() (Character &model);
};

#endif // FIGHTER_20_H
