#ifndef COAT_38_H
#define COAT_38_H

#include "equipment.h"

class Coat_38 : public Equipment { // 黑暗幽灵紫杉胸甲 Coat: 1
  public:
    Coat_38() {}
	void operator() (Character &model);
};

#endif // COAT_38_H
