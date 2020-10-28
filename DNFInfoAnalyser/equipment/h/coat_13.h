#ifndef COAT_13_H
#define COAT_13_H

#include "equipment.h"

class Coat_13 : public Equipment { // 神赐的抉择 Coat: 1
  public:
    Coat_13() {}
	void operator() (Character &model);
};

#endif // COAT_13_H
