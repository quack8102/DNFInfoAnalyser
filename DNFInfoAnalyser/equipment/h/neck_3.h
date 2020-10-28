#ifndef NECK_3_H
#define NECK_3_H

#include "equipment.h"

class Neck_3 : public Equipment { // 死亡阴影护肩 Neck: 0
  public:
    Neck_3() {}
	void operator() (Character &model);
};

#endif // NECK_3_H
