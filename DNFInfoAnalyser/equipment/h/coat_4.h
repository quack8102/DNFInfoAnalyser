#ifndef COAT_4_H
#define COAT_4_H

#include "equipment.h"

class Coat_4 : public Equipment { // 皇家裁决者审判外套 Coat: 1
  public:
    Coat_4() {}
	void operator() (Character &model);
};

#endif // COAT_4_H
