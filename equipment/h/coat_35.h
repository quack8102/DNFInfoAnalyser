#ifndef COAT_35_H
#define COAT_35_H

#include "equipment.h"

class Coat_35 : public Equipment { // 引路者的黄昏披风 Coat: 1
  public:
    Coat_35() {}
	void operator() (Character &model);
};

#endif // COAT_35_H
