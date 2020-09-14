#ifndef BELT_20_H
#define BELT_20_H

#include "equipment.h"

class Belt_20 : public Equipment { // 誓血之盟腰带 Belt: 3
  public:
    Belt_20() {}
	void operator() (Character &model);
};

#endif // BELT_20_H
