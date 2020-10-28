#ifndef PANTS_27_H
#define PANTS_27_H

#include "equipment.h"

class Pants_27 : public Equipment { // 霸域英豪护腿 Pants: 2
  public:
    Pants_27() {}
	void operator() (Character &model);
};

#endif // PANTS_27_H
