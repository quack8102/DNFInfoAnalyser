#ifndef COAT_5_H
#define COAT_5_H

#include "equipment.h"

class Coat_5 : public Equipment { // 战无不胜上衣 Coat: 1
  public:
    Coat_5() {}
	void operator() (Character &model);
};

#endif // COAT_5_H
