#ifndef COAT_0_H
#define COAT_0_H

#include "equipment.h"

class Coat_0 : public Equipment { // 大祭司的神启礼服 Coat: 1
  public:
    Coat_0() {}
	void operator() (Character &model);
};

#endif // COAT_0_H
