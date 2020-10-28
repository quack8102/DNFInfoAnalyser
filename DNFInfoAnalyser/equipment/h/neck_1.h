#ifndef NECK_1_H
#define NECK_1_H

#include "equipment.h"

class Neck_1 : public Equipment { // 魔法师[???]的披风 Neck: 0
  public:
    Neck_1() {}
	void operator() (Character &model);
};

#endif // NECK_1_H
