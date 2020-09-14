#ifndef FIGHTER_11_H
#define FIGHTER_11_H

#include "equipment.h"

class Fighter_11 : public Equipment { // 界·夜语黑瞳利爪 Fighter: 5
  public:
    Fighter_11() {}
	void operator() (Character &model);
};

#endif // FIGHTER_11_H
