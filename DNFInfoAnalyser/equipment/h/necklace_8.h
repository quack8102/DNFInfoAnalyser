#ifndef NECKLACE_8_H
#define NECKLACE_8_H

#include "equipment.h"

class Necklace_8 : public Equipment { // 维度定位项链 Necklace: 8
  public:
    Necklace_8() {}
	void operator() (Character &model);
};

#endif // NECKLACE_8_H
