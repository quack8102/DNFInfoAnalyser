#ifndef BRACELET_4_H
#define BRACELET_4_H

#include "equipment.h"

class Bracelet_4 : public Equipment { // 无尽的探求 Bracelet: 7
  public:
    Bracelet_4() {}
	void operator() (Character &model);
};

#endif // BRACELET_4_H
