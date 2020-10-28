#ifndef NECK_22_H
#define NECK_22_H

#include "equipment.h"

class Neck_22 : public Equipment { // 魔战无双肩甲 Neck: 0
  public:
    Neck_22() {}
	void operator() (Character &model);
};

#endif // NECK_22_H
