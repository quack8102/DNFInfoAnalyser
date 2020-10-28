#ifndef NECK_16_H
#define NECK_16_H

#include "equipment.h"

class Neck_16 : public Equipment { // 逝魔之灵悟肩甲 Neck: 0
  public:
    Neck_16() {}
	void operator() (Character &model);
};

#endif // NECK_16_H
