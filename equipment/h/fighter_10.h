#ifndef FIGHTER_10_H
#define FIGHTER_10_H

#include "equipment.h"

class Fighter_10 : public Equipment { // 夜语黑瞳利爪 Fighter: 5
  public:
    Fighter_10() {}
	void operator() (Character &model);
};

#endif // FIGHTER_10_H
