#ifndef BELT_5_H
#define BELT_5_H

#include "equipment.h"

class Belt_5 : public Equipment { // 浴血奋战腰带 Belt: 3
  public:
    Belt_5() {}
	void operator() (Character &model);
};

#endif // BELT_5_H
