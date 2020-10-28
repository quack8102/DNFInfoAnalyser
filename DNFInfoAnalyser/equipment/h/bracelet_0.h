#ifndef BRACELET_0_H
#define BRACELET_0_H

#include "equipment.h"

class Bracelet_0 : public Equipment { // 莱多：秩序创造者 Bracelet: 7
  public:
    Bracelet_0() {}
	void operator() (Character &model);
};

#endif // BRACELET_0_H
