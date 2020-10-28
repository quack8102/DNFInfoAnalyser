#ifndef COAT_8_H
#define COAT_8_H

#include "equipment.h"

class Coat_8 : public Equipment { // 摧枯拉朽胸甲 Coat: 1
  public:
    Coat_8() {}
	void operator() (Character &model);
};

#endif // COAT_8_H
