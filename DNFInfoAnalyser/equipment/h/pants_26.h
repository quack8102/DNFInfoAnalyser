#ifndef PANTS_26_H
#define PANTS_26_H

#include "equipment.h"

class Pants_26 : public Equipment { // 魔战无双腿甲 Pants: 2
  public:
    Pants_26() {}
	void operator() (Character &model);
};

#endif // PANTS_26_H
