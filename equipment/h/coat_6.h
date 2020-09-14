#ifndef COAT_6_H
#define COAT_6_H

#include "equipment.h"

class Coat_6 : public Equipment { // 爆裂大地之勇猛 Coat: 1
  public:
    Coat_6() {}
	void operator() (Character &model);
};

#endif // COAT_6_H
