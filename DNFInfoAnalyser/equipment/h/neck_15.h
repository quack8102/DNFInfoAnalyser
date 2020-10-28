#ifndef NECK_15_H
#define NECK_15_H

#include "equipment.h"

class Neck_15 : public Equipment { // 黑暗幽灵紫杉护肩 Neck: 0
  public:
    Neck_15() {}
	void operator() (Character &model);
};

#endif // NECK_15_H
