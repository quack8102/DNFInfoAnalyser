#ifndef COAT_28_H
#define COAT_28_H

#include "equipment.h"

class Coat_28 : public Equipment { // 撒旦：沸腾之怒 Coat: 1
  public:
    Coat_28() {}
	void operator() (Character &model);
};

#endif // COAT_28_H
