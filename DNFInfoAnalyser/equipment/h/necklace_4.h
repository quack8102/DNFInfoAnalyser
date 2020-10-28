#ifndef NECKLACE_4_H
#define NECKLACE_4_H

#include "equipment.h"

class Necklace_4 : public Equipment { // 堕落世界树之生命 Necklace: 8
  public:
    Necklace_4() {}
	void operator() (Character &model);
};

#endif // NECKLACE_4_H
