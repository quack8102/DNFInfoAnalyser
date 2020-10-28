#ifndef NECKLACE_1_H
#define NECKLACE_1_H

#include "equipment.h"

class Necklace_1 : public Equipment { // 驱散月光之黎明 Necklace: 8
  public:
    Necklace_1() {}
	void operator() (Character &model);
};

#endif // NECKLACE_1_H
