#ifndef PANTS_5_H
#define PANTS_5_H

#include "equipment.h"

class Pants_5 : public Equipment { // 破釜沉舟护腿 Pants: 2
  public:
    Pants_5() {}
	void operator() (Character &model);
};

#endif // PANTS_5_H
