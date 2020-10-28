#ifndef NECKLACE_9_H
#define NECKLACE_9_H

#include "equipment.h"

class Necklace_9 : public Equipment { // 冰雪公主的霜语项链 Necklace: 8
  public:
    Necklace_9() {}
	void operator() (Character &model);
};

#endif // NECKLACE_9_H
