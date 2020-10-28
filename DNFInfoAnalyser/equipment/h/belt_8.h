#ifndef BELT_8_H
#define BELT_8_H

#include "equipment.h"

class Belt_8 : public Equipment { // 风起云涌腰带 Belt: 3
  public:
    Belt_8() {}
	void operator() (Character &model);
};

#endif // BELT_8_H
