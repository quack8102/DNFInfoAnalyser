#ifndef COAT_41_H
#define COAT_41_H

#include "equipment.h"

class Coat_41 : public Equipment { // 逝魔之疾咒长袍 Coat: 1
  public:
    Coat_41() {}
	void operator() (Character &model);
};

#endif // COAT_41_H
