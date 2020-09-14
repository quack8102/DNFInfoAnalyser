#ifndef COAT_24_H
#define COAT_24_H

#include "equipment.h"

class Coat_24 : public Equipment { // 冲锋陷阵胸甲 Coat: 1
  public:
    Coat_24() {}
	void operator() (Character &model);
};

#endif // COAT_24_H
