#ifndef PANTS_16_H
#define PANTS_16_H

#include "equipment.h"

class Pants_16 : public Equipment { // 时空漩涡护腿 Pants: 2
  public:
    Pants_16() {}
	void operator() (Character &model);
};

#endif // PANTS_16_H
