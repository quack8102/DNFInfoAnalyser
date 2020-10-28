#ifndef PANTS_11_H
#define PANTS_11_H

#include "equipment.h"

class Pants_11 : public Equipment { // 千链锁灵护腿 Pants: 2
  public:
    Pants_11() {}
	void operator() (Character &model);
};

#endif // PANTS_11_H
