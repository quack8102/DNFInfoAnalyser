#ifndef COAT_14_H
#define COAT_14_H

#include "equipment.h"

class Coat_14 : public Equipment { // 生命脉动之地 Coat: 1
  public:
    Coat_14() {}
	void operator() (Character &model);
};

#endif // COAT_14_H
