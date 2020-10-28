#ifndef COAT_45_H
#define COAT_45_H

#include "equipment.h"

class Coat_45 : public Equipment { // 誓血之盟铠甲 Coat: 1
  public:
    Coat_45() {}
	void operator() (Character &model);
};

#endif // COAT_45_H
