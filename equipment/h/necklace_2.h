#ifndef NECKLACE_2_H
#define NECKLACE_2_H

#include "equipment.h"

class Necklace_2 : public Equipment { // 四叶草之初心 Necklace: 8
  public:
    Necklace_2() {}
	void operator() (Character &model);
};

#endif // NECKLACE_2_H
