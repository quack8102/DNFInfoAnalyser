#ifndef PANTS_12_H
#define PANTS_12_H

#include "equipment.h"

class Pants_12 : public Equipment { // 奔流不息之伽蓝 Pants: 2
  public:
    Pants_12() {}
	void operator() (Character &model);
};

#endif // PANTS_12_H
