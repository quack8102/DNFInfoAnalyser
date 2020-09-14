#ifndef COAT_33_H
#define COAT_33_H

#include "equipment.h"

class Coat_33 : public Equipment { // 宽恕坚韧之地 Coat: 1
  public:
    Coat_33() {}
	void operator() (Character &model);
};

#endif // COAT_33_H
