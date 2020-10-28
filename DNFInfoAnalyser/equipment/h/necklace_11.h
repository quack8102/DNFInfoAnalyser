#ifndef NECKLACE_11_H
#define NECKLACE_11_H

#include "equipment.h"

class Necklace_11 : public Equipment { // 千寻一醉 Necklace: 8
  public:
    Necklace_11() {}
	void operator() (Character &model);
};

#endif // NECKLACE_11_H
