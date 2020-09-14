#ifndef NECK_5_H
#define NECK_5_H

#include "equipment.h"

class Neck_5 : public Equipment { // 枪林弹雨护肩 Neck: 0
  public:
    Neck_5() {}
	void operator() (Character &model);
};

#endif // NECK_5_H
