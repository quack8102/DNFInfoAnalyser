#ifndef PANTS_24_H
#define PANTS_24_H

#include "equipment.h"

class Pants_24 : public Equipment { // 誓血之盟腿甲 Pants: 2
  public:
    Pants_24() {}
	void operator() (Character &model);
};

#endif // PANTS_24_H
