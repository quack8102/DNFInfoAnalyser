#ifndef PANTS_23_H
#define PANTS_23_H

#include "equipment.h"

class Pants_23 : public Equipment { // 最佳球手的奇袭长裤 Pants: 2
  public:
    Pants_23() {}
	void operator() (Character &model);
};

#endif // PANTS_23_H
