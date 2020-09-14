#ifndef COAT_2_H
#define COAT_2_H

#include "equipment.h"

class Coat_2 : public Equipment { // 浪漫旋律华尔兹 Coat: 1
  public:
    Coat_2() {}
	void operator() (Character &model);
};

#endif // COAT_2_H
