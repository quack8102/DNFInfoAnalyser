#ifndef COAT_34_H
#define COAT_34_H

#include "equipment.h"

class Coat_34 : public Equipment { // 堕落深渊黑魔法衬衫 Coat: 1
  public:
    Coat_34() {}
	void operator() (Character &model);
};

#endif // COAT_34_H
