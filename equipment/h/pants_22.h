#ifndef PANTS_22_H
#define PANTS_22_H

#include "equipment.h"

class Pants_22 : public Equipment { // 天御炎袭护腿 Pants: 2
  public:
    Pants_22() {}
	void operator() (Character &model);
};

#endif // PANTS_22_H
