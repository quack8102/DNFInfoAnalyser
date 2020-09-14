#ifndef COAT_22_H
#define COAT_22_H

#include "equipment.h"

class Coat_22 : public Equipment { // 死亡阴影夹克 Coat: 1
  public:
    Coat_22() {}
	void operator() (Character &model);
};

#endif // COAT_22_H
