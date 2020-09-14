#ifndef PANTS_21_H
#define PANTS_21_H

#include "equipment.h"

class Pants_21 : public Equipment { // 血舞之牙护腿 Pants: 2
  public:
    Pants_21() {}
	void operator() (Character &model);
};

#endif // PANTS_21_H
