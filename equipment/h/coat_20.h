#ifndef COAT_20_H
#define COAT_20_H

#include "equipment.h"

class Coat_20 : public Equipment { // 魔法师[???]的长袍 Coat: 1
  public:
    Coat_20() {}
	void operator() (Character &model);
};

#endif // COAT_20_H
