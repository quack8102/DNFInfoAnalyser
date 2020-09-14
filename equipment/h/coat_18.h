#ifndef COAT_18_H
#define COAT_18_H

#include "equipment.h"

class Coat_18 : public Equipment { // 灭世之怒 Coat: 1
  public:
    Coat_18() {}
	void operator() (Character &model);
};

#endif // COAT_18_H
