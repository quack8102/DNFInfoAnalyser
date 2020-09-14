#ifndef NECKLACE_3_H
#define NECKLACE_3_H

#include "equipment.h"

class Necklace_3 : public Equipment { // 冷焰之冰-温蒂妮 Necklace: 8
  public:
    Necklace_3() {}
	void operator() (Character &model);
};

#endif // NECKLACE_3_H
