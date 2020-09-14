#ifndef NECK_8_H
#define NECK_8_H

#include "equipment.h"

class Neck_8 : public Equipment { // 排山倒海护肩 Neck: 0
  public:
    Neck_8() {}
	void operator() (Character &model);
};

#endif // NECK_8_H
