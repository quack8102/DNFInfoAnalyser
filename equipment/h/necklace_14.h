#ifndef NECKLACE_14_H
#define NECKLACE_14_H

#include "equipment.h"

class Necklace_14 : public Equipment { // 百变千蛛 Necklace: 8
  public:
    Necklace_14() {}
	void operator() (Character &model);
};

#endif // NECKLACE_14_H
