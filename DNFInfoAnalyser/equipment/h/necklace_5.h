#ifndef NECKLACE_5_H
#define NECKLACE_5_H

#include "equipment.h"

class Necklace_5 : public Equipment { // 引路者的四季项链 Necklace: 8
  public:
    Necklace_5() {}
	void operator() (Character &model);
};

#endif // NECKLACE_5_H
