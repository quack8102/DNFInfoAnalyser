#ifndef COAT_15_H
#define COAT_15_H

#include "equipment.h"

class Coat_15 : public Equipment { // 深渊囚禁者长袍 Coat: 1
  public:
    Coat_15() {}
	void operator() (Character &model);
};

#endif // COAT_15_H
