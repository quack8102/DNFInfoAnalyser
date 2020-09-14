#ifndef BRACELET_10_H
#define BRACELET_10_H

#include "equipment.h"

class Bracelet_10 : public Equipment { // 白象之庇护 Bracelet: 7
  public:
    Bracelet_10() {}
	void operator() (Character &model);
};

#endif // BRACELET_10_H
