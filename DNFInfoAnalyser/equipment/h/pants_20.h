#ifndef PANTS_20_H
#define PANTS_20_H

#include "equipment.h"

class Pants_20 : public Equipment { // 逝魔之暴烈长裤 Pants: 2
  public:
    Pants_20() {}
	void operator() (Character &model);
};

#endif // PANTS_20_H
