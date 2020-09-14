#ifndef BELT_18_H
#define BELT_18_H

#include "equipment.h"

class Belt_18 : public Equipment { // 天御凝霜战甲 Belt: 3
  public:
    Belt_18() {}
	void operator() (Character &model);
};

#endif // BELT_18_H
