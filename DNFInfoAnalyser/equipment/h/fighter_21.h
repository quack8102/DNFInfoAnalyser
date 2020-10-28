#ifndef FIGHTER_21_H
#define FIGHTER_21_H

#include "equipment.h"

class Fighter_21 : public Equipment { // 界·夜语黑瞳东方棍 Fighter: 5
  public:
    Fighter_21() {}
	void operator() (Character &model);
};

#endif // FIGHTER_21_H
