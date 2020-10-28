#ifndef COAT_37_H
#define COAT_37_H

#include "equipment.h"

class Coat_37 : public Equipment { // 泣血之恨 Coat: 1
  public:
    Coat_37() {}
	void operator() (Character &model);
};

#endif // COAT_37_H
