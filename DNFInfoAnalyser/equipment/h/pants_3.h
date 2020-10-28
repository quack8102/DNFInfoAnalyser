#ifndef PANTS_3_H
#define PANTS_3_H

#include "equipment.h"

class Pants_3 : public Equipment { // 死亡阴影短裤 Pants: 2
  public:
    Pants_3() {}
	void operator() (Character &model);
};

#endif // PANTS_3_H
