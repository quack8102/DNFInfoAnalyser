#ifndef COAT_40_H
#define COAT_40_H

#include "equipment.h"

class Coat_40 : public Equipment { // 轮回：黑暗幽灵紫杉胸甲 Coat: 1
  public:
    Coat_40() {}
	void operator() (Character &model);
};

#endif // COAT_40_H
