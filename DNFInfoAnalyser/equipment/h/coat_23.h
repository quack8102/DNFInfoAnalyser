#ifndef COAT_23_H
#define COAT_23_H

#include "equipment.h"

class Coat_23 : public Equipment { // 首席执行官裁决夹克 Coat: 1
  public:
    Coat_23() {}
	void operator() (Character &model);
};

#endif // COAT_23_H
