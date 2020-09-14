#ifndef COAT_16_H
#define COAT_16_H

#include "equipment.h"

class Coat_16 : public Equipment { // 圣者的黄昏披风 Coat: 1
  public:
    Coat_16() {}
	void operator() (Character &model);
};

#endif // COAT_16_H
