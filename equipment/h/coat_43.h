#ifndef COAT_43_H
#define COAT_43_H

#include "equipment.h"

class Coat_43 : public Equipment { // 天御雷罚战甲 Coat: 1
  public:
    Coat_43() {}
	void operator() (Character &model);
};

#endif // COAT_43_H
