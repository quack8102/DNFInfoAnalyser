#ifndef NECK_4_H
#define NECK_4_H

#include "equipment.h"

class Neck_4 : public Equipment { // 首席执行官裁决肩甲 Neck: 0
  public:
    Neck_4() {}
	void operator() (Character &model);
};

#endif // NECK_4_H
