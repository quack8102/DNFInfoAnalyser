#ifndef COAT_21_H
#define COAT_21_H

#include "equipment.h"

class Coat_21 : public Equipment { // 优雅旋律华尔兹 Coat: 1
  public:
    Coat_21() {}
	void operator() (Character &model);
};

#endif // COAT_21_H
