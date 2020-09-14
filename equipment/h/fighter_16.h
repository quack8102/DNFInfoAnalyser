#ifndef FIGHTER_16_H
#define FIGHTER_16_H

#include "equipment.h"

class Fighter_16 : public Equipment { // 界·夜语黑瞳拳套 Fighter: 5
  public:
    Fighter_16() {}
	void operator() (Character &model);
};

#endif // FIGHTER_16_H
