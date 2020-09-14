#ifndef COAT_17_H
#define COAT_17_H

#include "equipment.h"

class Coat_17 : public Equipment { // 逆转结局 Coat: 1
  public:
    Coat_17() {}
	void operator() (Character &model);
};

#endif // COAT_17_H
