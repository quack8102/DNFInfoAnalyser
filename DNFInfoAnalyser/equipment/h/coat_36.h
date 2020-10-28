#ifndef COAT_36_H
#define COAT_36_H

#include "equipment.h"

class Coat_36 : public Equipment { // 地狱边缘 Coat: 1
  public:
    Coat_36() {}
	void operator() (Character &model);
};

#endif // COAT_36_H
