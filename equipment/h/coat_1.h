#ifndef COAT_1_H
#define COAT_1_H

#include "equipment.h"

class Coat_1 : public Equipment { // 大魔法师[???]的长袍 Coat: 1
  public:
    Coat_1() {}
	void operator() (Character &model);
};

#endif // COAT_1_H
