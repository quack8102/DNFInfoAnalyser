#ifndef NECK_17_H
#define NECK_17_H

#include "equipment.h"

class Neck_17 : public Equipment { // 冥殇之刃肩甲 Neck: 0
  public:
    Neck_17() {}
	void operator() (Character &model);
};

#endif // NECK_17_H
