#ifndef COAT_32_H
#define COAT_32_H

#include "equipment.h"

class Coat_32 : public Equipment { // 人性的抉择 Coat: 1
  public:
    Coat_32() {}
	void operator() (Character &model);
};

#endif // COAT_32_H
